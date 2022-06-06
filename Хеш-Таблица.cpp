#include <iostream>
#include <list>

using namespace std;

class HashTable{
private:
	list<int> *table;
	int total_elements;

	// Хэш-функция для вычисления хэша для значения:
	int getHash(int key){
		return key % total_elements;
	}

public:
	// Конструктор для создания хэш-таблицы с 'n' индексами:
	HashTable(int n){
		total_elements = n;
		table = new list<int>[total_elements];
	}

	// Вставка данных в хэш-таблицу:
	void insertElement(int key){
		table[getHash(key)].push_back(key);
	}

	// Удаление данных из хэш-таблицы:
	void removeElement(int key){
		int x = getHash(key);

		list<int>::iterator i;
		for (i = table[x].begin(); i != table[x].end(); i++) {
			//Проверьте, указывает ли итератор на требуемый элемент:
			if (*i == key)
				break;
		}

		// Если элемент был найден в списке, то удалите его:
		if (i != table[x].end())
			table[x].erase(i);
	}

	void printAll(){
		// Пройдите по каждому индексу:
		for (int i = 0; i < total_elements; i++){
			cout << "Index " << i << ": ";
			// Пройдите по списку по текущему индексу:
			for (int j : table[i])
				cout << j << " => ";

			cout << endl;
		}
	}
};

int main() {
	HashTable ht(3);
	int arr[10];
	for (int i = 0; i < 10; i++){
		cout << "[" << i + 1 << "]" << ": ";
		cin >> arr[i];
	}
	// Вставьте все данные в хэш-таблицу:
	for (int i = 0; i < 10; i++)
		ht.insertElement(arr[i]);

	cout << "..:: Hash Table ::.." << endl;
	ht.printAll();
	system("pause");
	return 0;
}