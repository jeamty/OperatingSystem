//PCB.h
#ifndef _PCB_H
#define _PCB_H
#include <iostream>
//ProcessControlBlock
class PCB {
public :
	PCB ();
	PCB (const std::string & , const int & , const int & ,void (*processPtr) ()) ;
	//���ƹ��캯��
	PCB (const PCB &) ;
	//���ظ�ֵ�������
	PCB &operator= (const PCB & ) ;
	~PCB();
	static PCB * inputForCreatPCB() ;
	std::string PCB_ID ;//���̱�ʶ
	int priority;//�������ȼ� 
	int runtime ;//ʱ��Ƭ 
	PCB *previous ;//ǰһ������ 
	PCB *next ;//��һ������ 
	//����ָ��
	typedef void (*functionPtr) () ;
	functionPtr processPtr ;
};
#endif
