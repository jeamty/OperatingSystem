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





#$(target):MemoryItem.o MemoryField.o main.o
#	$(cc) -o $(target)  MemoryItem.o MemoryField.o main.o
#main.o: main.cpp
#	$(cc) -o main.o -c main.cpp  
#MemoryField.o: MemoryField.cpp MemoryField.h
#	$(cc) -o MemoryField.o -c MemoryField.cpp  
#MemoryIiem.o: MemoryItem.cpp MemoryItem.h
#	$(cc) -o MemoryItem.o -c MemoryItem.cpp  
#clean:
#	rm $(target) MemoryItem.o MemoryField.o main.o


