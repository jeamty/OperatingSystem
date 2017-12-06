cc = g++ -std=c++11 
app:MemoryItem.o MemoryField.o main.o
	$(cc) -o app  MemoryItem.o MemoryField.o main.o
main.o: main.cpp
	$(cc) -o main.o -c main.cpp  
MemoryField.o: MemoryField.cpp MemoryField.h
	$(cc) -o MemoryField.o -c MemoryField.cpp  
MemoryIiem.o: MemoryItem.cpp MemoryItem.h
	$(cc) -o MemoryItem.o -c MemoryItem.cpp  
clean:
	rm app MemoryItem.o MemoryField.o main.o


