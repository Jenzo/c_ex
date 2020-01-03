all: tictactoe.o player.o computerplayer.o humanplayer.o gameboard.o gamemaster.o minimax.o
	g++ tictactoe.o player.o computerplayer.o humanplayer.o gameboard.o gamemaster.o minimax.o -o minimax
		
player.o: player.cpp
	g++ -c player.cpp

computerplayer.o: computerplayer.cpp
	g++ -c computerplayer.cpp

humanplayer.o: humanplayer.cpp
	g++ -c humanplayer.cpp

gameboard.o: gameboard.cpp
	g++ -c gameboard.cpp
	
tictactoe.o: tictactoe.cpp
	g++ -c tictactoe.cpp

gamemaster.o: gamemaster.cpp
	g++ -c gamemaster.cpp
	
minimax.o: minimax.cpp
	g++ -c minimax.cpp	

clean: 
	rm *.o minimax		