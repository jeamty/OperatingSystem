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
	cout << "�ɱ����������Ӧ�����㷨(First Adaptive Allocation Algorithm )�����ڴ�\n" ;
	cout << "1:256MB\n2:512MB\n3:1024MB\n" ;
	cout << "ѡ���ڴ��С��" ;
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
		cout << "1:�����ڴ�\n2:�ͷ��ڴ�\n3:�˳�\n" ;
		cout << "ѡ��������ͣ�" ;
		choice = 0 ;
		cin >> choice ;
		switch (choice) {
			case 1 : {
				cout << "������ҵ��С��" ;
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
				cout << "��ǰ�ڴ������Ϊ[0,"<<memoryField.m_count<<"),����Ҫ�ͷŵ��ڴ�����:" ;
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
