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
//复制构造函数
PCB::PCB (const PCB &pcb) {
	//忽略previous & next
	this->PCB_ID = pcb.PCB_ID ;
	this->priority = pcb.priority ;
	this->runtime = pcb.runtime ;
	this->processPtr = pcb.processPtr ;
}
//重载赋值运算算符
PCB &PCB::operator= (const PCB & pcb ) {
	//赋值时，忽略previous & next
	this->PCB_ID = pcb.PCB_ID ;
	this->priority = pcb.priority ;
	this->runtime = pcb.runtime ;
	this->processPtr = pcb.processPtr ;
	return *this ;
}
//销毁PCB节点
PCB::~PCB(){	
	this->previous = nullptr ;
	this->next = nullptr ;
	this->processPtr = nullptr ;
} 
//由输入创建一个PCB
PCB * PCB::inputForCreatPCB() {
	string PCB_ID ;
	int priority ;
	int runtime ;
	cout << "输入进程ID：";
	cin >> PCB_ID ;
	cout << "输入进程优先级:";
	cin >> priority ;
	cout << "输入进程运行时间:";
	cin >> runtime ;
	PCB *p = new PCB(PCB_ID,priority,runtime) ;
	return p ;
}
