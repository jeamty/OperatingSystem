//main.cpp
#include "MemoryField.h"
#include "MemoryItem.h"
#include <iostream>
using namespace std ;
void MemoryMamagement() ;

int main() {	
	MemoryMamagement () ;
}
void MemoryMamagement() {
	cout << "可变分区最先适应分配算法(First Adaptive Allocation Algorithm )分配内存\n" ;
	cout << "1:256MB\n2:512MB\n3:1024MB\n" ;
	cout << "选择内存大小：" ;
	bool status = true ;
	unsigned int size = 0 ;
	int choice ; 
	while (status) {
		cin >> choice ;
		switch (choice) {
			case 1 : {
				size = 256 ;
				status = false ;
				break;
			}
			case 2 : {
				size = 512 ;
				status = false ;
				break;
			}
			case 3 : {
				size = 1024 ;
				status = false ;
				break;
			}
			default : {
				cout << "Invalid input . Please input again . " ;
				break;
			}
		}
	} 
	MemoryField memoryField(size) ;
	memoryField.m_printMemory() ;
	status = true ;
	while (status) {
		cout << "1:分配内存\n2:释放内存\n3:退出\n" ;
		cout << "选择操作类型：" ;
		choice = 0 ;
		cin >> choice ;
		switch (choice) {
			case 1 : {
				cout << "输入作业大小：" ;
				unsigned workSize = 0 ;
				cin >> workSize ;
				if (memoryField.m_allocateMemory(workSize) ) {
					cout << "a successful allocation .\n" ;
					memoryField.m_printMemory() ;
				}else {
					cout << "a failing allocation .\n" ;
				}
				break; 
			}
			case 2 : {
				cout << "当前内存分区号为[0,"<<memoryField.m_count<<"),输入要释放的内存区号:" ;
				int number = 0 ;
				cin >> number ;
				if ( number < 0 || number >= memoryField.m_count ) {
					cout << "Invalid input .\n" ;
					break ;
				} 
				if (memoryField.m_freeMemory(number) ) {
					cout << "a successful free memory .\n" ;
					memoryField.m_printMemory() ;
				}else {
					cout << "a failing free memory .\n" ;
				}
				break;
			}
			case 3 : {
				status = false ;
				break;
			}
			default : {
				cout << "Invalid input . Please input again . \n" ;
				break;
			}
		}
	}
} 
