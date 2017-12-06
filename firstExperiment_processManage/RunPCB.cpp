//RunPCB.cpp
#include <iostream>
#include "RunPCB.h"
#include "PCB_Queue.h"
#include "PCB.h"
#include <string>
#include <iomanip>
using namespace std ;
//���̹���(����) 
void RunPCB::processManage( PCB_Queue *&queue ) {
	PCB *pcb = nullptr ;
	cout << "���̵��Ƚ��:\n" ;
	cout << "+------+--------+-------+-----------------------------------+\n" ;
	cout << "|PCB_ID|priority|runtime|process content                    |\n" ;
	cout << "+------+--------+-------+-----------------------------------+\n" ;
	while (!queue->empty()) {
		pcb = queue->pop() ;//����һ��Ԫ�� 
		if ( pcb == nullptr ) 
			return ;
		cout << setiosflags(ios::left) << "|" <<setw(6) << pcb->PCB_ID <<"|" << setw(8) <<pcb->priority<<"|" << setw(7) <<pcb->runtime ;
		if (pcb->runtime >= ONCE_RUN_TIME  )
			cout << "|"  << "������" << setw(3) << ONCE_RUN_TIME << "ms:" ;
		else 
			cout << "|"  << "������" << setw(3) << pcb->runtime << "ms:" ;
		//ִ��ONCE_RUN_TIMEʱ��		
		if (pcb->processPtr!=nullptr){
			cout  << setw(23) ;
			pcb->processPtr();
			cout << "|\n" ;	
		}
			
		if (pcb->runtime <= this->ONCE_RUN_TIME ) {
			delete pcb ;//�ý���ִ���꣬���ٸý���
			pcb = nullptr ;
		} 
		else {
			pcb->runtime -= this->ONCE_RUN_TIME ;
			queue->push(pcb) ;
		}
		
	}
	cout << "+------+--------+-------+-----------------------------------+" << endl ;
} 
