//MemoryIiem.cpp
#include "MemoryItem.h" 

//构造函数，初始化存分配表项 
MemoryItem::MemoryItem( unsigned int m_item  ) {
	m_setAddress(m_item>>12) ;
	m_setLength(m_item<<20>>21) ;
	m_setStatus(m_item<<31>>31) ;
}
//获得分区地址
unsigned int MemoryItem::m_getAddress () {
	return (m_item>>12) ;
}
//设置分区地址
void MemoryItem::m_setAddress (unsigned int address ) {
	if ( address > 0xfffff000 || address < 0 )
		throw "address out of range ." ;
	address = address << 12 ;
	//原m_item的address位 置零 
	m_item = m_item << 20 ; 
	m_item = m_item >> 20 ; 
	//设置新address
	m_item = m_item ^ address ;
}
//获得分区长度 
unsigned int MemoryItem::m_getLength () {
	return (m_item<<20>>21) ;
}
//设置分区长度 
void MemoryItem::m_setLength (unsigned int length ) {
	if ( length > 0xffe || length < 0 )
		throw "length out of range ." ;
	length = length << 1 ;
	//原m_item的length位 置零 
	m_item = m_item & 0xfffff001 ;
	//设置新length
	m_item = m_item ^ length ;
}
//获得分区状态 
bool MemoryItem::m_getStatus () {
	return (m_item & 0x1) ? true : false ;
}
//设置分区状态
void MemoryItem::m_setStatus (bool status ) {
	if (status) 
		m_item = m_item | 0x1 ;
	else 
		m_item = m_item >>1 << 1 ;
}

/* 
#include <iostream>
using namespace std ;
int main() {
	MemoryItem it(123456) ;
	cout<<"#"<<it.m_getAddress()<<"#\n" ;
	cout<<"#"<<it.m_getLength()<<"#\n" ;
	cout<<"#"<<it.m_getStatus()<<"#\n" ;
	return 0 ;
}
*/
