//PCB_Queue.h

#ifndef _PCB_QUEUE_H
#define _PCB_QUEUE_H
class PCB ;//前置声明 PCB 类 //或#include "PCB.h"
class RunPCB ;//前置声明 RunPCB 类 //或#include "RunPCB.h"

//extern void RunPCB::processManage(PCB_Queue *&) ;

//processControlBlockQueue
class PCB_Queue {
public :
	//初始化头结点
	PCB_Queue() ;
	~PCB_Queue() ;
	bool empty () ;
	void createPCBLink ( const int  ) ;
	void processAppend ( const PCB &) ;
//	friend void RunPCB::processManage(PCB_Queue *&) ;
	friend class RunPCB ;
private :
	PCB *pop () ;
	void push (PCB *const ) ;
	void bubbleSortForPCBPriority () ;
	PCB *front ;//队首
	PCB *rear ;//队尾
} ;

#endif

