//Worker id, name, surname, age, pageCount
//WorkerQueue
//Printer workerQueue
//start - 
//Printer clasinin ichinde workerQueue saxlanilmalidir
//ve printer in start methodu chagrilan kimi
//novbede olan ishchilerin kagizlari ksersks olsun
//kserks emeliyyati bitenden sonra ishci siradan dequeue olunsun
//novbe boshalana qeder bu proses davam etmelidir

//Worker
//WorkerQueue = >
//Printer = > WorkerQueue obj.start()

#include <iostream>
#include <assert.h>
#include <queue>
#include <windows.h>

using namespace std;

class Worker {
	static int idCounter;
	int id;
	string name;
	string surname;
	int age;
	int pageCount;

public:

	Worker() {
		id = idCounter++;
		string name = "";
		string surname = "";
		int age = 0;
		int pageCount = 0;
	}


	Worker(string name, string surname, int age, int pageCount) {
		id = idCounter++;
		SetName(name);
		SetSurName(surname);
		SetAge(age);
		SetPageCount(pageCount);
	}

	int GetId()const { return id; }

	string GetName()const { return name; }

	string GetSurName()const { return surname; }

	int GetAge()const { return age; }

	int GetpageCount() const { return pageCount; }



	void SetName(const string name) {
		this->name = name;
	}

	void SetSurName(const string surname) {
		this->surname = surname;
	}

	void SetAge(const int age) {
		this->age = age;
	}

	void SetPageCount(const int pageCount) {
		this->pageCount = pageCount;
	}

	void Print() {
		cout << "Id : " << id << endl
			<< "Name : " << name << endl
			<< "Surname : " << surname << endl
			<< "Age : " << age << endl
			<< "Pagecount : " << pageCount << endl;
	}


	friend class Printer;
};

int Worker::idCounter = 1;


class WorkerQueue {
	Worker* arr = nullptr;
	int capacity = 0;
	int front = 0;
	int rear = -1;
	int count = 0;
public:

	WorkerQueue() = default;

	WorkerQueue(int size) {
		capacity = size;
		arr = new Worker[capacity];
		front = 0;
		rear = -1;
		count = 0;
	}


	bool IsEmpty() { return rear == -1; }
	bool IsFull() { return count == capacity; }


	void Push(Worker& value) {
		assert(!IsFull() && "Queue is full");
		arr[++rear] = value;
		count++;
	}

	void Pop() {
		assert(!IsEmpty());
		for (int i = 0; i < count - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		count--;
		rear--;
	}

	Worker& Front() {
		assert(!IsEmpty() && "Queue is empty");
		return arr[front];
	}

};


class Printer {
	WorkerQueue t;



public:
	Printer() = default;

	Printer(WorkerQueue& value) {
		t = value;
	}

	void addWorker(Worker worker) {
		t.Push(worker);
	}


	void Start() {
		Worker worker = t.Front();
		while (worker.pageCount > 0)
		{
			system("cls");
			worker.Print();
			Sleep(1000);
			worker.pageCount--;
		}
		t.Pop();
	}
};

int main() {


	Worker huseyn("Huseyn", "Mammadov", 22, 3);
	Worker saxa("Saxa", "Tanriverdiyev", 20, 5);
	Worker bahruz("Bahruz", "Nezerli", 12, 4);

	WorkerQueue y(3);
	Printer t(y);
	t.addWorker(huseyn);
	t.addWorker(saxa);
	t.addWorker(bahruz);

	t.Start();
	t.Start();
	t.Start();

}