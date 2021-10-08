Project2.exe : 
	g++ -o Project2.exe customer.hpp customer.cpp FIFO.hpp FIFO.cpp priority.hpp priority.cpp Simulation.cpp
	./Project2.exe


run :
	./Project2.exe

clean :
	rm *.o
	rm *.gch
	rm *.exe
	
