//main.cpp
#include "PCB_Queue.h"
#include "RunPCB.h"
#include "PCB.h"
#include <iostream>

int main () {
	std::cout << "时间片轮转(Round Robin ,RR）调度算法" << std::endl ;
	//初始化进程
	PCB_Queue *h = new PCB_Queue() ;
	//第一步，初始化进程，创建PCB链表 
	h->createPCBLink(2) ;
	h->processAppend(PCB("P3",1,44,[](){std::cout<<"This is NO.3 process !";})) ;
	h->processAppend(PCB("P4",4,8,[](){std::cout<<"This is NO.4 process !";})) ;
	RunPCB cpu ;
	//第二步，进行cpu调度 
	cpu.processManage(h) ;
	delete h ;
	return 0 ;
}
