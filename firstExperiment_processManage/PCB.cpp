//PCB.cpp

#include "PCB.h"
#include <iostream>
#include <string>
using namespace std ;
PCB::PCB ():previous(nullptr),next(nullptr),processPtr(nullptr){	} 
PCB::PCB (const std::string &PCB_ID , const int &priority , const int &runtime,void (*processPtr) () = nullptr )
	: previous(nullptr),next(nullptr),processPtr(processPtr) {
	this->PCB_ID = PCB_ID ;
	this->priority = priority ;
	if ( runtime < 0 ){
		throw "Invalid input that runtime is out of range ." ;
	}
		
	this->runtime = runtime ;
}
//���ƹ��캯��
PCB::PCB (const PCB &pcb) {
	//����previous & next
	this->PCB_ID = pcb.PCB_ID ;
	this->priority = pcb.priority ;
	this->runtime = pcb.runtime ;
	this->processPtr = pcb.processPtr ;
}
//���ظ�ֵ�������
PCB &PCB::operator= (const PCB & pcb ) {
	//��ֵʱ������previous & next
	this->PCB_ID = pcb.PCB_ID ;
	this->priority = pcb.priority ;
	this->runtime = pcb.runtime ;
	this->processPtr = pcb.processPtr ;
	return *this ;
}
//����PCB�ڵ�
PCB::~PCB(){	
	this->previous = nullptr ;
	this->next = nullptr ;
	this->processPtr = nullptr ;
} 
//�����봴��һ��PCB
PCB * PCB::inputForCreatPCB() {
	string PCB_ID ;
	int priority ;
	int runtime ;
	cout << "�������ID��";
	cin >> PCB_ID ;
	cout << "����������ȼ�:";
	cin >> priority ;
	cout << "�����������ʱ��:";
	cin >> runtime ;
	PCB *p = new PCB(PCB_ID,priority,runtime) ;
	return p ;
}
