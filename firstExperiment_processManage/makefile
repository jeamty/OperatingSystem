cc=g++ -std=c++11
src=$(wildcard ./*.cpp)
obj=$(patsubst ./%.cpp,./%.o,$(src))
target=app
$(target):$(obj)
	$(cc) -o $@ $^
%.o:%.cpp
	$(cc) -o $@ -c $<
.PHONY:clean
clean:
	-rm -f $(target) $(obj) 


#$(target):main.o PCB.o PCB_Queue.o RunPCB.o 
#	$(cc) -o $(target) main.o PCB.o PCB_Queue.o RunPCB.o 
#main.o:main.cpp 
#	$(cc) -o main.o -c main.cpp
#RunPCB.o:RunPCB.cpp RunPCB.h
#	$(cc) -o RunPCB.o -c RunPCB.cpp
#PCB_Queue.o:PCB_Queue.cpp PCB_Queue.h
#	$(cc) -o PCB_Queue.o -c PCB_Queue.cpp
#PCB.o:PCB.cpp PCB.h
#	$(cc) -o PCB.o -c PCB.cpp 
#clean:
#	rm $(target) main.o PCB_Queue.o RunPCB.o PCB.o
