//MemoryField.h
#ifndef _MEMORY_FIELD_H
#define _MEMORY_FIELD_H
#include "MemoryItem.h" 
//�ڴ��� 
class MemoryField {
public :
	//���캯������ʼ���ڴ� 
	MemoryField (unsigned int ) ;
	//��ӡ�ڴ���Ϣ
	void m_printMemory () ;
	//�����ڴ�
	bool m_allocateMemory (unsigned int) ;
	//�ͷ��ڴ����
	bool m_freeMemory(int) ;
	//��������
	~MemoryField () ; 
	
	static unsigned int const ITEM_COUNT = 100 ; 
	unsigned int m_count ;	//�洢�ڴ���Ŀ����
private :
	MemoryItem *m_itemSet[ITEM_COUNT] ;		//�ڴ���Ŀ��
	unsigned int m_size ;	//�洢�����ڴ��С 
	//�����·����ڵ�
	bool m_insertItem (int,MemoryItem *) ;
	//�ж��Ƿ����ڿ��з��� 
	bool m_isEmptyWithUpMemory (int) ; 
	//�ж��Ƿ����ڿ��з���
	bool m_isEmptyWithDownMemory (int) ;
	//�ϲ����з���(���ºϲ�)
	bool m_mergeMemory (int) ;
	//ɾ����ǰ�����ڵ� 
	bool m_deleteItem (int) ;
};
#endif


