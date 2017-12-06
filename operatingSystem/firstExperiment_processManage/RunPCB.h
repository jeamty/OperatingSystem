//RunPCB.h

#ifndef _RUNPCB_H
#define _RUNPCB_H

class PCB_Queue ;//前置声明 PCB_Queue 类 //或#include "PCB_Queue.h"
class RunPCB {
public :
	RunPCB (int ONCE_RUN_TIME = 20 ):ONCE_RUN_TIME(ONCE_RUN_TIME) {		}
	//进程调度 
	void processManage (PCB_Queue *&) ;
	const int ONCE_RUN_TIME ;
} ;
#endif
