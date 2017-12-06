//PCB.h
#ifndef _PCB_H
#define _PCB_H
#include <iostream>
//ProcessControlBlock
class PCB {
public :
	PCB ();
	PCB (const std::string & , const int & , const int & ,void (*processPtr) ()) ;
	//复制构造函数
	PCB (const PCB &) ;
	//重载赋值运算算符
	PCB &operator= (const PCB & ) ;
	~PCB();
	static PCB * inputForCreatPCB() ;
	std::string PCB_ID ;//进程标识
	int priority;//进程优先级 
	int runtime ;//时间片 
	PCB *previous ;//前一个进程 
	PCB *next ;//下一个进程 
	//进程指针
	typedef void (*functionPtr) () ;
	functionPtr processPtr ;
};
#endif
