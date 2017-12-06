//MemoryField.h
#ifndef _MEMORY_FIELD_H
#define _MEMORY_FIELD_H
#include "MemoryItem.h" 
//内存区 
class MemoryField {
public :
	//构造函数，初始化内存 
	MemoryField (unsigned int ) ;
	//打印内存信息
	void m_printMemory () ;
	//分配内存
	bool m_allocateMemory (unsigned int) ;
	//释放内存分区
	bool m_freeMemory(int) ;
	//析构函数
	~MemoryField () ; 
	
	static unsigned int const ITEM_COUNT = 100 ; 
	unsigned int m_count ;	//存储内存项目个数
private :
	MemoryItem *m_itemSet[ITEM_COUNT] ;		//内存项目集
	unsigned int m_size ;	//存储整个内存大小 
	//插入新分区节点
	bool m_insertItem (int,MemoryItem *) ;
	//判断是否上邻空闲分区 
	bool m_isEmptyWithUpMemory (int) ; 
	//判断是否下邻空闲分区
	bool m_isEmptyWithDownMemory (int) ;
	//合并空闲分区(向下合并)
	bool m_mergeMemory (int) ;
	//删除当前分区节点 
	bool m_deleteItem (int) ;
};
#endif


