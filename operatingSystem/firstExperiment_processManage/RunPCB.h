//RunPCB.h

#ifndef _RUNPCB_H
#define _RUNPCB_H

class PCB_Queue ;//ǰ������ PCB_Queue �� //��#include "PCB_Queue.h"
class RunPCB {
public :
	RunPCB (int ONCE_RUN_TIME = 20 ):ONCE_RUN_TIME(ONCE_RUN_TIME) {		}
	//���̵��� 
	void processManage (PCB_Queue *&) ;
	const int ONCE_RUN_TIME ;
} ;
#endif
