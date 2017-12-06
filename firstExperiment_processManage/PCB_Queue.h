//PCB_Queue.h

#ifndef _PCB_QUEUE_H
#define _PCB_QUEUE_H
class PCB ;//ǰ������ PCB �� //��#include "PCB.h"
class RunPCB ;//ǰ������ RunPCB �� //��#include "RunPCB.h"

//extern void RunPCB::processManage(PCB_Queue *&) ;

//processControlBlockQueue
class PCB_Queue {
public :
	//��ʼ��ͷ���
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
	PCB *front ;//����
	PCB *rear ;//��β
} ;

#endif

