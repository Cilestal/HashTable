#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;

//�������� ��� �������� ������
template <class  K, class  V>
struct Entry {
	K key;
	V value;
	Entry<K,V> *next;
};

template <class  K, class  V> class LinkedList{
private:
    Entry<K,V> *head;					//������ ������
    int length;						//����� ������
public:
    LinkedList<K, V>();					
    void insert(Entry<K,V> *newItem);	//������� ������ �������� � ������
    bool remove(K itemKey);    //�������� �������� �� ������
    Entry<K,V> *get(K itemKey);	    //��������� �������� �� ������
    void print();					//������ �������� ������

    int getLength();				//��������� ����� ������
	void clear();					//�������� ��������� �� ������
    ~LinkedList();
};

template<class K, class V>
LinkedList<K, V>::LinkedList() {
	//�������������� ������ ������
	head = new Entry<K,V>;
	head->next = NULL;
	length = 0;
}

template<class K, class V>
void LinkedList<K, V>::insert(Entry<K, V> *newItem) {
	if (!head->next) {			//���� ������ ����
		head->next = newItem;	//������ ������ ��������� �� ����� �������
		length++;
		return;
	}

	//���� ��������� �������
	Entry<K,V> *prev = head, *q = head;
	while (q) {
		prev = q;
		q = prev->next;
	}
	//��������� ������ �� ����� �������
	prev->next = newItem;
	newItem->next = NULL;
	length++;
}

template<class K, class V>
bool LinkedList<K, V>::remove(K itemKey) {
	//���� ������ ����, ������
	if (!head->next)
		return false;

	//���� ������ �������
	Entry<K,V> *prev = head, *el = head;
	while (el) {
		if (el->key == itemKey) {
			//������� ���
			prev->next = el->next;
			delete el;
			length--;
			return true;
		}
		prev = el;
		el = prev->next;
	}
	return false;
}

template<class K, class V>
Entry<K,V> *LinkedList<K, V>::get(K itemKey) {
	Entry<K,V> *p = head, *q = head;
	while (q) {
		p = q;
		if ((p != head) && (p->key == itemKey))
			return p;
		q = p->next;
	}
	return NULL;
}

template<class K, class V>
void LinkedList<K, V>::print() {
	//���� ����
	if (length == 0) {
		cout << "\n{ }\n";
		return;
	}
	Entry<K,V> *p = head, *q = head;
	cout << "\n{ ";
	while (q) {
		p = q;
		if (p != head) {
			cout << p->key;
			if (p->next) cout << ", ";
			else cout << " ";
		}
		q = p->next;
	}
	cout << "}\n";
}

template<class K, class V>
int LinkedList<K, V>::getLength() {
	return length;
}

template<class K, class V>
void LinkedList<K, V>::clear() {
	//������� ������
	Entry<K,V> *tmp;
	while (head->next) {
		tmp = head->next;
		head->next = tmp->next;
		delete tmp;
	}

	this->head->next = NULL;
	this->length = 0;
}

template<class K, class V>
LinkedList<K, V>::~LinkedList() {
	Entry<K,V>  *p = head, *q = head;
	clear();
	delete head;
}

#endif
 
