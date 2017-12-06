//MemoryField.cpp

#include "MemoryField.h"
#include "MemoryItem.h"
#include <iostream>
#include <iomanip>
using namespace std ; 

//���캯������ʼ���ڴ� 
MemoryField::MemoryField (unsigned size ) : m_size(size) , m_count(0) {
	MemoryItem *item = new MemoryItem() ;
	if ( !item )
		throw "out of memory ." ;
	//��ʼ���ڴ����Ŀ
	item->m_setAddress(0) ;
	item->m_setLength(size) ;
	item->m_setStatus(false) ;
	
	*(m_itemSet + m_count) = item ;
	m_count ++ ; 
}
//��������
	MemoryField::~MemoryField() {
		for (int i = 0 ; i < m_count - 1 ; i++ ) {
			delete *(m_itemSet + i) ;
			*(m_itemSet + i) = nullptr ;	
		}
	} 
//��ӡ�ڴ���Ϣ
void MemoryField::m_printMemory () {
	cout << "��ǰ�ڴ����������£�\n" ; 
	cout << "+------+----------------+------------+-------------------------+\n" ;
	cout << "|������|������ַ(16����)|��������(MB)|����״̬(0:����,1:�ѷ���)|\n" ;
	cout << "+------+----------------+------------+-------------------------+\n" ;
	for ( int i = 0 ; i < m_count ; i++ ) {
		cout << "|" << setw(6) << setiosflags(ios::left) << i  ;
		cout << "|0x" << hex << setw(14) << setiosflags(ios::left) << ( *(m_itemSet + i ) )->m_getAddress() ; 
		cout << "|" << dec << setw(12) << setiosflags(ios::left) <<( *(m_itemSet + i ) )->m_getLength() ;
		cout << "|" << setw(25) << setiosflags(ios::left) << ( *(m_itemSet + i ) )->m_getStatus() << "|"<< endl ;  
	}
	cout << "+------+----------------+------------+-------------------------+" << endl ;
}
//�����ڴ�
bool MemoryField::m_allocateMemory (unsigned int workSize ) {
	if ( workSize == 0 ) {
		cerr << "�������С�ڴ�Ϊ1" << endl;
		return false ; 
	}
	bool status = false ;//����״̬ 
	//������Ӧ
	for ( int i = 0 ; i < m_count ; i++ ) {
		//��ǰ����״̬Ϊ���� �� ��ǰ�������ȴ��ڵ��ڴ�װ�����ҵ���� 
		if( (*(m_itemSet+i))->m_getStatus() == false && (*(m_itemSet+i))->m_getLength() >= workSize ) {
			if ( (*(m_itemSet+i))->m_getLength() == workSize )
				(*(m_itemSet+i))->m_setStatus(true) ;
			else {
				//�µĿ��з��� 
				MemoryItem *it = new MemoryItem() ;
				it->m_setAddress( (*(m_itemSet+i))->m_getAddress() + workSize ) ;
				it->m_setLength( (*(m_itemSet+i))->m_getLength() - workSize ) ;
				it->m_setStatus(false) ;
				//���µĿ��з���ע�ᵽ�ڴ����� 
				m_insertItem(i+1,it) ; 
				//�����ɷ��� 
				(*(m_itemSet+i))->m_setLength(workSize) ;
				(*(m_itemSet+i))->m_setStatus(true) ;
			}
			status = true ;
			break ;
		}
	}
	return status ;
}
//�����·����ڵ�
bool MemoryField::m_insertItem (int position ,MemoryItem *item ) {
	if ( position > m_count || position < 0 ) {
		cerr << "position out of range ." ;
		return false ;
	}
	if ( !item ) {
		cerr << "�����·����ڵ�ΪNULL" ;
		return false ;
	}
	//��������λ�õ���Ŀ���������Ŀ��������ƶ�һ��λ�ã��ճ������λ�� 
	for (int i = m_count - 1 ; i >= position ; i-- ) {
		*(m_itemSet + i + 1) = *(m_itemSet + i ) ;
	}
	m_count++ ;
	*(m_itemSet+position) = item ;
	return true ;
}
//�ͷ��ڴ����
bool MemoryField::m_freeMemory( int position ) {
	if ( position > m_count || position < 0 ) {
		cerr << "position out of range ." ;
		return false ;
	}
	//��������ڴ汾�����ǿ��е�
	if ((*(m_itemSet+position) )->m_getStatus() == false ) {
		cerr << "����" << position << "�ķ���״̬�Ѿ�Ϊ���У������ظ��ͷ� ." ;
		return false ;
	}
	//����ǰ����״̬��Ϊ����
	(*(m_itemSet+position) )->m_setStatus(false) ;
	bool hadMerge = false ;
	if (m_isEmptyWithUpMemory(position) ) {
		m_mergeMemory(position-1) ;
		hadMerge = true ;
	}
	if (hadMerge ) {
		if (m_isEmptyWithDownMemory(position-1)) {
			m_mergeMemory(position-1) ;	
		}
	}else {
		if (m_isEmptyWithDownMemory(position)) {
			m_mergeMemory(position) ;	
			hadMerge = true ;
		}
	}
	if ( !hadMerge )
		(*(m_itemSet+position))->m_setStatus(false) ;
	return true ;
}
//�ж��Ƿ����ڿ��з��� 
bool MemoryField::m_isEmptyWithUpMemory (int position) {
	//��ǰ����Ϊ 0 ������û����һ������ 
	if ( position == 0 )
		return false ;
	return !(*(m_itemSet+position-1))->m_getStatus() ;
}
//�ж��Ƿ����ڿ��з���
bool MemoryField::m_isEmptyWithDownMemory (int position) {
	//��ǰ����Ϊ ��������û����һ������ 
	if ( position == m_count - 1 ) {
		return false ;
	}
	return !(*(m_itemSet+position+1))->m_getStatus() ;
}
//�ϲ����з���(���ºϲ�,�����ڴ���Ŀ��Ŵ�ķ���)
bool MemoryField::m_mergeMemory (int position) {
	//��Ϊ�ú���ֻ�� m_freeMemory ���ã����Լ��� position ������Ч�� 
	unsigned int length = (*(m_itemSet+position))->m_getLength() + (*(m_itemSet+position+1))->m_getLength() ;
	(*(m_itemSet+position))->m_setLength(length) ;
	(*(m_itemSet+position))->m_setStatus(false) ;
	m_deleteItem (position+1) ;
	return true ;
}
//ɾ����ǰ�����ڵ� 
bool MemoryField::m_deleteItem (int position ) {
	//��Ϊ�ú���ֻ�� m_mergeMemory ���ã����Լ��� position ������Ч�� 
	delete *(m_itemSet + position) ;
	*(m_itemSet + position) = nullptr ;
	for (int i = position ; i < m_count - 1 ; i++ ) {
		(*(m_itemSet + i)) = (*(m_itemSet + i + 1)) ;
	}
	m_count-- ;
	return true ;
}


