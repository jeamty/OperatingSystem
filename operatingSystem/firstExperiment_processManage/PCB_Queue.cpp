//PCB_Queue.cpp
#include <iostream>
#include "PCB_Queue.h"
#include "PCB.h"
using namespace std ;

//初始化头结点
PCB_Queue::PCB_Queue():front(nullptr),rear(nullptr){ 	}
//销毁队列
PCB_Queue::~PCB_Queue() {
	this->front = nullptr ;
	this->rear = nullptr ;
} 
//判断队列是否为空 
bool PCB_Queue::empty () {
	if ( this->rear == nullptr )
		return true ;
	else return false ; 
}
//进队
void PCB_Queue::push( PCB *const p) {
	if ( this->empty () ) {
		this->front=this->rear = p ;//第一个节点 
		p->previous = p->next = nullptr ;
	}
	else {
		//不是第一个节点
		p->previous = this->rear ;
		this->rear->next = p ;
		this->rear = p ;
		this->rear->next = nullptr ;
	}
} 
//出队
PCB *PCB_Queue::pop() {
	PCB *ret = nullptr ;
	if (this->empty())
		return ret ;//队列为空
	else {
		//将出队的next & previous 指针置空 
		ret = this->front ;
		
		this->front = this->front->next ;
		if (this->front != nullptr) //当原队列元素大于等于两个时 
			this->front->previous = nullptr ;//将队首的 previous 指针置空
		else {		
			this->rear = nullptr ;//当原队列元素只有一个时 
		}
		ret->next = nullptr ;//原队首的 previous 本来就已经为nullptr了 
	} 
	return ret ;
}
//队列按优先级排序
void PCB_Queue::bubbleSortForPCBPriority () {
	bool exchange = false ;
	PCB temp ;//由	~PCB() 释放内存 
	for (PCB *i = this->front ; i != nullptr ; i=i->next ) {
		exchange = false ;
		for ( PCB *j = this->rear ; j != i ; j=j->previous ) {
			if ( j->priority > (j->previous)->priority ) {//将进程按照优先级进行从大到小排序 (对首到对尾)
				temp = *j ;
				*j = *(j->previous) ;
				*(j->previous) = temp ;	
				exchange = true ;
			}
		}
		if (!exchange)
			return ;
	}  
} 

//创建PCB链表 
void PCB_Queue::createPCBLink ( const int count = 0 ) {

	//
	for (int i = 0 ; i < count ; i++ ) {
		PCB *p = PCB::inputForCreatPCB() ;
		p->processPtr = [](){std::cout<<"Hello World !" ;} ;
		//进队
		this->push(p) ;
	}
	//将进程按照优先级进行从大到小排序 
	this->bubbleSortForPCBPriority() ;
}
//加入一个线程到线程队列
void PCB_Queue::processAppend (const PCB &pcb ) {
	PCB *p = new PCB (pcb) ;
	this->push(p) ;//插入队尾
	this->bubbleSortForPCBPriority() ;//排序一次
}



