#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <jpeglib.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * @brief Contains color data for a single pixel.
 *
 *
 */
struct pixel_rgb_t {
	unsigned r : 8;
	unsigned g : 8;
	unsigned b : 8;
};

/**
 * @brief Defines an image size.
 */
struct image_size_t {
	unsigned int width;
	unsigned int height;
};

typedef struct pixel_rgb_t pixel_rgb_t;
typedef struct image_size_t image_size_t;

/**
 * @brief Scales an image by applying a billinear interpolation filter.
 *
 * @param in pixel data of input image
 * @param out  pixel data of output image. Has to be pre allocated.
 * @param src_sz the size of the input image
 * @param trgt_sz the desired output size.
 */
void resize_image(pixel_rgb_t *in, pixel_rgb_t *out, image_size_t src_sz, image_size_t trgt_sz) {

#warning Task 3: Write your code here.

}

/**
 * @brief Loads pixel data from a JPEG file into memory.
 *
 * In this method the *current_pixel points to the addess of the first index of given pixel_data
 * and it will be filled with each color channel information from the
 * current scanline pixel and will be incremented after each filling.
 *
 * @param name the path of the file to read
 * @param img pointer to pixel data. Will be allocated.
 * @param size the size of the image. Will be set by this function
 */
void load_jpeg(const char *name, pixel_rgb_t **img, image_size_t *const size) {
	uint8_t r, g, b;
	int width, height;
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	FILE *infile;
	JSAMPARRAY pJpegBuffer;
	int row_stride;

	if ((infile = fopen(name, "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", name);
		exit(1);
	}
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, infile);
	(void) jpeg_read_header(&cinfo, TRUE);
	(void) jpeg_start_decompress(&cinfo);

	width = cinfo.output_width;
	height = cinfo.output_height;

	// Allokierung von Speicherblöcken.
	*img = calloc((size_t) width * height, sizeof(pixel_rgb_t));
	pixel_rgb_t *current_pixel = *img;

	if (!*img) {
		printf("NO MEM FOR JPEG CONVERT!\n");
		exit(1);
	}

	// Reihenbreite als Produkt von 3 Komponenten (Rot, Grün, Blau) und Anzahl Pixel pro Scanline
	row_stride = width * cinfo.output_components;
	pJpegBuffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

	while (cinfo.output_scanline < cinfo.output_height) {
		(void) jpeg_read_scanlines(&cinfo, pJpegBuffer, 1);
		for (int x = 0; x < width; x++) {
			r = pJpegBuffer[0][cinfo.output_components * x];
			if (cinfo.output_components > 2) {
				g = pJpegBuffer[0][cinfo.output_components * x + 1];
				b = pJpegBuffer[0][cinfo.output_components * x + 2];
			} else {
				g = r;
				b = r;
			}

			//r, g and b contain the color information for the channels red, green and blue
			// current_pixel is your current pixel to fill with info from the jpeg.

			current_pixel->r = r;
			current_pixel->g = g;
			current_pixel->b = b;


			current_pixel++;
		}
	}

	fclose(infile);
	(void) jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);

	size->height = (uint32_t) height;
	size->width = (uint32_t) width;

}

/**
 * @brief Writes pixel data to a JPEG file with 80% quality and defined image size.
 *
 * In this method there is a pointer[current_row] who points to the begin of the allocated block
 * and a pointer to the input_data[pixel_data] we want to save.
 * We iterate over each pixel per scanline of given size, assign the current pixel data at position current_row
 * to current, which points to the first element of current row. The increase the position of current to assign each color value.
 * Finally assign the row_pointer to current_row pointer to write the current scanline into out file.
 *
 * @param pixel_data the pixel to compress
 * @param size the size of this image
 * @param filename path to write this file to.
 */
void save_jpeg(const pixel_rgb_t *pixel_data, const image_size_t size, const char *filename) {

	FILE *outfile = fopen(filename, "wb");

	if (!outfile) {
		fprintf(stderr, "can't open %s\n for write", filename);
		exit(1);
	}

	struct jpeg_compress_struct jpeg_info;
	struct jpeg_error_mgr jpeg_error;

	jpeg_info.err = jpeg_std_error(&jpeg_error);
	jpeg_create_compress(&jpeg_info);
	jpeg_stdio_dest(&jpeg_info, outfile);

	jpeg_info.image_width = size.width;
	jpeg_info.image_height = size.height;
	jpeg_info.input_components = 3;
	jpeg_info.in_color_space = JCS_RGB;

	jpeg_set_defaults(&jpeg_info);
	jpeg_set_quality(&jpeg_info, 80, true);
	jpeg_start_compress(&jpeg_info, true);

	JSAMPROW row_pointer;

	unsigned char *row = malloc(sizeof(unsigned char) * 3 * size.width);

	// iterate scanlines (rows)
	while (jpeg_info.next_scanline < jpeg_info.image_height) {

		//current is your current scanline to fill with information.
		unsigned char *current = row;

		//this is the index of the beginning of the current row in your source array.
		unsigned int current_row = jpeg_info.next_scanline * size.width;


		for(int i = 0 ; i < size.width*3; current_row++){
			current[i++] = pixel_data[current_row].r;
			current[i++] = pixel_data[current_row].g;
			current[i++] = pixel_data[current_row].b;
		}

		row_pointer = (JSAMPROW) row;
		jpeg_write_scanlines(&jpeg_info, &row_pointer, true);
	}

	free(row);

	jpeg_finish_compress(&jpeg_info);
}

/**
 * @brief This main method reads 4 command line arguments
 * -i : name of input file
 * -o : name of desired output file
 * -w : new width of desired output file
 * -h : new height of desired output file
 *
 *  Note that all arguments are required.
 *  Arguments -w & -h must have minimum size of 1.
 *  If one of these arguments is invalid, a error message will be printed
 *  and program exits with status code 1.
 */
int main(int argc, char **argv) {

	char *input_file;
	char *output_file;

	int new_height = -1;
	int new_width = -1;

	pixel_rgb_t pixel;
	image_size_t size;

	char ch;
	while ((ch = getopt(argc, argv, "i:o:w:h:")) != -1) {
		switch (ch) {
		case 'i':
			input_file = optarg;
			break;
		case 'o':
			output_file = optarg;
			break;
		case 'h':
			new_height = atoi(optarg);
			if(new_height < 1){
				puts("invalid height parameter. height must greater than 0!");
				exit(1);
			}
			break;
		case 'w':
			new_width = atoi(optarg);
			if(new_width < 1){
				puts("invalid width parameter. width must greater than 0!");
				exit(1);
			}
			break;
		default:
			puts("unknown argument!");
			exit(1);
		}
	}

	if(new_width == -1 || new_height == -1){
		puts("missing target size parameters");
		exit(1);
	}

	image_size_t new_size_t = {new_width, new_height};

	pixel_rgb_t *p_ptr = &pixel;
	image_size_t *img_ptr = &size;

	load_jpeg(input_file, &p_ptr, img_ptr);
	save_jpeg(p_ptr, size, output_file);

	return 0;
}
