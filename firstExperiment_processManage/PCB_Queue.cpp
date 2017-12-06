//PCB_Queue.cpp
#include <iostream>
#include "PCB_Queue.h"
#include "PCB.h"
using namespace std ;

//��ʼ��ͷ���
PCB_Queue::PCB_Queue():front(nullptr),rear(nullptr){ 	}
//���ٶ���
PCB_Queue::~PCB_Queue() {
	this->front = nullptr ;
	this->rear = nullptr ;
} 
//�ж϶����Ƿ�Ϊ�� 
bool PCB_Queue::empty () {
	if ( this->rear == nullptr )
		return true ;
	else return false ; 
}
//����
void PCB_Queue::push( PCB *const p) {
	if ( this->empty () ) {
		this->front=this->rear = p ;//��һ���ڵ� 
		p->previous = p->next = nullptr ;
	}
	else {
		//���ǵ�һ���ڵ�
		p->previous = this->rear ;
		this->rear->next = p ;
		this->rear = p ;
		this->rear->next = nullptr ;
	}
} 
//����
PCB *PCB_Queue::pop() {
	PCB *ret = nullptr ;
	if (this->empty())
		return ret ;//����Ϊ��
	else {
		//�����ӵ�next & previous ָ���ÿ� 
		ret = this->front ;
		
		this->front = this->front->next ;
		if (this->front != nullptr) //��ԭ����Ԫ�ش��ڵ�������ʱ 
			this->front->previous = nullptr ;//�����׵� previous ָ���ÿ�
		else {		
			this->rear = nullptr ;//��ԭ����Ԫ��ֻ��һ��ʱ 
		}
		ret->next = nullptr ;//ԭ���׵� previous �������Ѿ�Ϊnullptr�� 
	} 
	return ret ;
}
//���а����ȼ�����
void PCB_Queue::bubbleSortForPCBPriority () {
	bool exchange = false ;
	PCB temp ;//��	~PCB() �ͷ��ڴ� 
	for (PCB *i = this->front ; i != nullptr ; i=i->next ) {
		exchange = false ;
		for ( PCB *j = this->rear ; j != i ; j=j->previous ) {
			if ( j->priority > (j->previous)->priority ) {//�����̰������ȼ����дӴ�С���� (���׵���β)
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

//����PCB���� 
void PCB_Queue::createPCBLink ( const int count = 0 ) {

	//
	for (int i = 0 ; i < count ; i++ ) {
		PCB *p = PCB::inputForCreatPCB() ;
		p->processPtr = [](){std::cout<<"Hello World !" ;} ;
		//����
		this->push(p) ;
	}
	//�����̰������ȼ����дӴ�С���� 
	this->bubbleSortForPCBPriority() ;
}
//����һ���̵߳��̶߳���
void PCB_Queue::processAppend (const PCB &pcb ) {
	PCB *p = new PCB (pcb) ;
	this->push(p) ;//�����β
	this->bubbleSortForPCBPriority() ;//����һ��
}



