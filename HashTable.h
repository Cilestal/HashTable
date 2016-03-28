#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

const int DEFAULT_INITIAL_CAPACITY = 16;

template<class K, class V>
class HashTable{
private:
    LinkedList<K, V> *table;						//������� ������ - "�������"
    int length;												//����� �������
    int hash(K itemKey);								//������� ��������� hashcode 
	Entry<K, V> *getEntry(K key);			//�-��� ��������� ������
public:
    HashTable<K, V>(int tableLength = DEFAULT_INITIAL_CAPACITY);
    void put(K key, V value);		//�������� ������� � �������
    bool remove(K key);				//������� ������� �� �������
	V getValue(K key);			//�������� �������� �������� �� �����
	bool contains(K key);				//�������� �� ���������� �������� �����

	void clear();							//������� �������
    void printTable();						//������ �������
    void printHistogram();					//������ �����������
    int getLength();						//������ �������
    int size();								//���-�� ��������� � �������
    ~HashTable();
};

template<class K, class V>
HashTable<K, V>::HashTable<K, V>(int tableLength) {
	//�������������� �������
	if (tableLength <= 0)
		tableLength = DEFAULT_INITIAL_CAPACITY;

	table = new LinkedList<K, V>[tableLength];
	length = tableLength;
}

//������� ��������� hashcode
template<class K, class V>
int HashTable<K, V>::hash(K key) {
	return (std::hash<K>()(key) & 2147483647) % this->length;
}

//���������� �������� � �������
template<class K, class V>
void HashTable<K, V>::put(K key, V value) {
	//������� ������ � ������ � ���������
	Entry<K, V> *entry = new Entry<K, V>{ key, value, NULL };

	//���������� ������ "�������"
	int index = hash(entry->key);

	//��������� ������� � ������ "�������"
	table[index].insert(entry);
}

template<class K, class V>
bool HashTable<K, V>::remove(K key) {
	int index = hash(key);
	return table[index].remove(key);
}

template<class K, class V>
Entry<K, V> *HashTable<K, V>::getEntry(K key) {
	int index = hash(key);
	return table[index].get(key);
}

template<class K, class V>
V HashTable<K, V>::getValue(K key) {
	//���� ������ � ���������� � ��������
	return this->getEntry(key)->value;
}

template<class K, class V>
bool HashTable<K, V>::contains(K key) {
	//���� ������, ���� ��� �������, �� ������� �������� ����� �������
	return this->getEntry(key) != NULL;
}

template<class K, class V>
void HashTable<K, V>::clear() {
	//������ ������ "�������"
	for (int i = 0; i < length; i++) {
		table[i].clear();
	}
}

template<class K, class V>
void HashTable<K, V>::printTable() {
	cout << "\nHash Table:\n";
	for (int i = 0; i < length; i++) {
		cout << "Bucket " << i + 1 << ": ";
		table[i].print();
	}
}

template<class K, class V>
void HashTable<K, V>::printHistogram() {
	cout << "\n\nHash Table Contains ";
	cout << size() << " Items total\n";
	for (int i = 0; i < length; i++) {
		cout << i + 1 << ":\t";
		//�������� ������� �����, ������� ��������� � "�������"
		for (int j = 0; j < table[i].getLength(); j++) cout << " X";
		cout << "\n";
	}
}

template<class K, class V>
int HashTable<K, V>::getLength() {
	return length;
}

template<class K, class V>
int HashTable<K, V>::size() {
	//��������� ���-�� ��������� � ������ �� ������
	int itemCount = 0;
	for (int i = 0; i < length; i++)
		itemCount += table[i].getLength();
	return itemCount;
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
	delete[] table;
}
#endif


