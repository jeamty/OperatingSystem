//main.cpp
#include "PCB_Queue.h"
#include "RunPCB.h"
#include "PCB.h"
#include <iostream>

int main () {
	std::cout << "ʱ��Ƭ��ת(Round Robin ,RR�������㷨" << std::endl ;
	//��ʼ������
	PCB_Queue *h = new PCB_Queue() ;
	//��һ������ʼ�����̣�����PCB���� 
	h->createPCBLink(2) ;
	h->processAppend(PCB("P3",1,44,[](){std::cout<<"This is NO.3 process !";})) ;
	h->processAppend(PCB("P4",4,8,[](){std::cout<<"This is NO.4 process !";})) ;
	RunPCB cpu ;
	//�ڶ���������cpu���� 
	cpu.processManage(h) ;
	delete h ;
	return 0 ;
}
