//RunPCB.cpp
#include <iostream>
#include "RunPCB.h"
#include "PCB_Queue.h"
#include "PCB.h"
#include <string>
#include <iomanip>
using namespace std ;
//进程管理(调度) 
void RunPCB::processManage( PCB_Queue *&queue ) {
	PCB *pcb = nullptr ;
	cout << "进程调度结果:\n" ;
	cout << "+------+--------+-------+-----------------------------------+\n" ;
	cout << "|PCB_ID|priority|runtime|process content                    |\n" ;
	cout << "+------+--------+-------+-----------------------------------+\n" ;
	while (!queue->empty()) {
		pcb = queue->pop() ;//出队一个元素 
		if ( pcb == nullptr ) 
			return ;
		cout << setiosflags(ios::left) << "|" <<setw(6) << pcb->PCB_ID <<"|" << setw(8) <<pcb->priority<<"|" << setw(7) <<pcb->runtime ;
		if (pcb->runtime >= ONCE_RUN_TIME  )
			cout << "|"  << "运行了" << setw(3) << ONCE_RUN_TIME << "ms:" ;
		else 
			cout << "|"  << "运行了" << setw(3) << pcb->runtime << "ms:" ;
		//执行ONCE_RUN_TIME时间		
		if (pcb->processPtr!=nullptr){
			cout  << setw(23) ;
			pcb->processPtr();
			cout << "|\n" ;	
		}
			
		if (pcb->runtime <= this->ONCE_RUN_TIME ) {
			delete pcb ;//该进程执行完，销毁该进程
			pcb = nullptr ;
		} 
		else {
			pcb->runtime -= this->ONCE_RUN_TIME ;
			queue->push(pcb) ;
		}
		
	}
	cout << "+------+--------+-------+-----------------------------------+" << endl ;
} 
