//MemoryItem.h

#ifndef _MEMORY_ITEM_H
#define _MEMORY_ITEM_H
//内存分配表项 
class MemoryItem {
public :
	MemoryItem (unsigned int m_item = 0 ) ;
	//获得分区地址 
	unsigned int m_getAddress () ;
	//设置分区地址 
	void m_setAddress (unsigned int) ;
	//获得分区长度 
	unsigned int m_getLength () ;
	//设置分区长度 
	void m_setLength (unsigned int) ;
	//获得分区状态 
	bool m_getStatus () ;
	//设置分区状态 
	void m_setStatus (bool) ;
private :
	/*
	*	m_item 的 [d31,d12](高20位) 共20 bit 保存分区首地址 ,取值范围：[0,2^20-1] 
	*	m_item 的 [d11,d1] 共11 bit 保存分区长度 ,取值范围：[0,2^11-1] 
	*	m_item 的 d0 共1 bit 保存分区状态信息 ,取值范围：[0,1] 
	*/
	unsigned int m_item ; 
};
#endif
