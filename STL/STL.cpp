#include <iostream>

using namespace std;

class Queue
{
private:
	int* art;
	int capacity;
	int front = 0;
	int rear = -1;

public:
	Queue(int size)
	{
		capacity = size;
		art = new int[capacity];
	}

	bool isEmpty()
	{
		return rear == -1;
	}

	void enqueue(int n)
	{
		if (rear + 1 >= capacity)
		{
			cout << "Queue is full" << endl;
			return;
		}
		art[++rear] = n;
		cout << "ok" << endl;
		//cout << "Enqueue rear: " << rear << endl;
	}

	void dequeue()
	{
		if (isEmpty())
		{
			cout << "error" << endl;
		}
		int value = art[front];
		for (int i = front; i < rear; i++)
		{
			art[i] = art[i + 1];
		}
		rear--;
		cout << value << endl;
	}

	void frontElement()
	{
		if (isEmpty()) cout << "error" << endl;;
		cout << art[front] << endl;
	}

	int size()
	{
		return rear + 1;
	}

	void clear()
	{
		rear = -1;
		cout << "ok" << endl;
	}

	void exit()
	{
		cout << "bye" << endl;
	}

	void output()
	{
		if (!isEmpty())
		{
			cout << "Output: ";
			for (int i = front; i <= rear; i++)
			{
				cout << art[i] << " ";
			}
			cout << endl;
		}
	}

};

int main()
{
	Queue queue = Queue(100);
	string command = "";
	int value;
	while (command != "exit")
	{
		cin >> command;
		//cout << "--- " << command << endl;
		if (command == "push")
		{
			cin >> value;
			queue.enqueue(value);
		}
		else if (command == "front")
		{
			queue.frontElement();
		}
		else if (command == "size")
		{
			cout << queue.size() << endl;
		}
		else if (command == "pop")
		{
			int result = queue.dequeue();
			if (result == -1) cout << "error" << endl;
			else cout << result << endl;
		}
		else if (command == "clear")
		{
			queue.clear();
		}
		else if (command == "exit")
		{
			queue.exit();
			break;
		}
		//queue.output();
	}
	
}
