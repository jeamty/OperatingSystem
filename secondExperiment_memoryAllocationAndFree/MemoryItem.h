//MemoryItem.h

#ifndef _MEMORY_ITEM_H
#define _MEMORY_ITEM_H
//�ڴ������� 
class MemoryItem {
public :
	MemoryItem (unsigned int m_item = 0 ) ;
	//��÷�����ַ 
	unsigned int m_getAddress () ;
	//���÷�����ַ 
	void m_setAddress (unsigned int) ;
	//��÷������� 
	unsigned int m_getLength () ;
	//���÷������� 
	void m_setLength (unsigned int) ;
	//��÷���״̬ 
	bool m_getStatus () ;
	//���÷���״̬ 
	void m_setStatus (bool) ;
private :
	/*
	*	m_item �� [d31,d12](��20λ) ��20 bit ��������׵�ַ ,ȡֵ��Χ��[0,2^20-1] 
	*	m_item �� [d11,d1] ��11 bit ����������� ,ȡֵ��Χ��[0,2^11-1] 
	*	m_item �� d0 ��1 bit �������״̬��Ϣ ,ȡֵ��Χ��[0,1] 
	*/
	unsigned int m_item ; 
};
#endif
