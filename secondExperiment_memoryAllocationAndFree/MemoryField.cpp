//MemoryField.cpp

#include "MemoryField.h"
#include "MemoryItem.h"
#include <iostream>
#include <iomanip>
using namespace std ; 

//构造函数，初始化内存 
MemoryField::MemoryField (unsigned size ) : m_size(size) , m_count(0) {
	MemoryItem *item = new MemoryItem() ;
	if ( !item )
		throw "out of memory ." ;
	//初始化内存表项目
	item->m_setAddress(0) ;
	item->m_setLength(size) ;
	item->m_setStatus(false) ;
	
	*(m_itemSet + m_count) = item ;
	m_count ++ ; 
}
//析构函数
	MemoryField::~MemoryField() {
		for (int i = 0 ; i < m_count - 1 ; i++ ) {
			delete *(m_itemSet + i) ;
			*(m_itemSet + i) = nullptr ;	
		}
	} 
//打印内存信息
void MemoryField::m_printMemory () {
	cout << "当前内存分配情况如下：\n" ; 
	cout << "+------+----------------+------------+-------------------------+\n" ;
	cout << "|分区号|分区首址(16进制)|分区长度(MB)|分区状态(0:空闲,1:已分配)|\n" ;
	cout << "+------+----------------+------------+-------------------------+\n" ;
	for ( int i = 0 ; i < m_count ; i++ ) {
		cout << "|" << setw(6) << setiosflags(ios::left) << i  ;
		cout << "|0x" << hex << setw(14) << setiosflags(ios::left) << ( *(m_itemSet + i ) )->m_getAddress() ; 
		cout << "|" << dec << setw(12) << setiosflags(ios::left) <<( *(m_itemSet + i ) )->m_getLength() ;
		cout << "|" << setw(25) << setiosflags(ios::left) << ( *(m_itemSet + i ) )->m_getStatus() << "|"<< endl ;  
	}
	cout << "+------+----------------+------------+-------------------------+" << endl ;
}
//分配内存
bool MemoryField::m_allocateMemory (unsigned int workSize ) {
	if ( workSize == 0 ) {
		cerr << "分配的最小内存为1" << endl;
		return false ; 
	}
	bool status = false ;//分配状态 
	//最先适应
	for ( int i = 0 ; i < m_count ; i++ ) {
		//当前分区状态为空闲 且 当前分区长度大于等于待装入的作业长度 
		if( (*(m_itemSet+i))->m_getStatus() == false && (*(m_itemSet+i))->m_getLength() >= workSize ) {
			if ( (*(m_itemSet+i))->m_getLength() == workSize )
				(*(m_itemSet+i))->m_setStatus(true) ;
			else {
				//新的空闲分区 
				MemoryItem *it = new MemoryItem() ;
				it->m_setAddress( (*(m_itemSet+i))->m_getAddress() + workSize ) ;
				it->m_setLength( (*(m_itemSet+i))->m_getLength() - workSize ) ;
				it->m_setStatus(false) ;
				//将新的空闲分区注册到内存分配表 
				m_insertItem(i+1,it) ; 
				//调整旧分区 
				(*(m_itemSet+i))->m_setLength(workSize) ;
				(*(m_itemSet+i))->m_setStatus(true) ;
			}
			status = true ;
			break ;
		}
	}
	return status ;
}
//插入新分区节点
bool MemoryField::m_insertItem (int position ,MemoryItem *item ) {
	if ( position > m_count || position < 0 ) {
		cerr << "position out of range ." ;
		return false ;
	}
	if ( !item ) {
		cerr << "插入新分区节点为NULL" ;
		return false ;
	}
	//将待插入位置的项目及后面的项目依次向后移动一个位置，空出插入的位置 
	for (int i = m_count - 1 ; i >= position ; i-- ) {
		*(m_itemSet + i + 1) = *(m_itemSet + i ) ;
	}
	m_count++ ;
	*(m_itemSet+position) = item ;
	return true ;
}
//释放内存分区
bool MemoryField::m_freeMemory( int position ) {
	if ( position > m_count || position < 0 ) {
		cerr << "position out of range ." ;
		return false ;
	}
	//如果该区内存本来就是空闲的
	if ((*(m_itemSet+position) )->m_getStatus() == false ) {
		cerr << "分区" << position << "的分区状态已经为空闲，无需重复释放 ." ;
		return false ;
	}
	//将当前分区状态置为空闲
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
//判断是否上邻空闲分区 
bool MemoryField::m_isEmptyWithUpMemory (int position) {
	//当前分区为 0 分区，没有上一个分区 
	if ( position == 0 )
		return false ;
	return !(*(m_itemSet+position-1))->m_getStatus() ;
}
//判断是否下邻空闲分区
bool MemoryField::m_isEmptyWithDownMemory (int position) {
	//当前分区为 最后分区，没有下一个分区 
	if ( position == m_count - 1 ) {
		return false ;
	}
	return !(*(m_itemSet+position+1))->m_getStatus() ;
}
//合并空闲分区(向下合并,即向内存项目编号大的方向)
bool MemoryField::m_mergeMemory (int position) {
	//因为该函数只被 m_freeMemory 调用，所以假设 position 都是有效的 
	unsigned int length = (*(m_itemSet+position))->m_getLength() + (*(m_itemSet+position+1))->m_getLength() ;
	(*(m_itemSet+position))->m_setLength(length) ;
	(*(m_itemSet+position))->m_setStatus(false) ;
	m_deleteItem (position+1) ;
	return true ;
}
//删除当前分区节点 
bool MemoryField::m_deleteItem (int position ) {
	//因为该函数只被 m_mergeMemory 调用，所以假设 position 都是有效的 
	delete *(m_itemSet + position) ;
	*(m_itemSet + position) = nullptr ;
	for (int i = position ; i < m_count - 1 ; i++ ) {
		(*(m_itemSet + i)) = (*(m_itemSet + i + 1)) ;
	}
	m_count-- ;
	return true ;
}


