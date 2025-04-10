#include <iostream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;

    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    };

};

class LinkedList
{
public:
    ListNode* head;
    ListNode* tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    bool Empty() const
    {
        if (head == nullptr) return true;
        return false;
    }
    void addFirst(int val)
    {
        ListNode* node = new ListNode(val);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
    }
    void addLast(int val)
    {
        ListNode* node = new ListNode(val);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
    bool removeFirst()
    {
        if (head == nullptr)
        {
            //cout << "The list is empty" << endl;
            return false;
        }
        else
        {
            ListNode* temp = head;
            head = head->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            delete(temp);
            return true;
        }
    }
    bool removeLast()
    {
        if (head == nullptr)
        {
            //cout << "The list is empty" << endl;
            return false;
        }
        else if (head == tail)
        {
            delete(head);
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            ListNode* node = head;
            while (node->next != tail)
            {
                node = node->next;
            }
            delete(tail);
            tail = node;
            tail->next = nullptr;
            return true;
        }
    }
    void Print()
    {
        if (head == nullptr)
        {
            //cout << "The list is empty" << endl;
            return;
        }
        ListNode* node = head;
        while (node != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
    int size() 
    {
        int size = 0;
        if (head == nullptr)
        {
            return size;
        }
        ListNode* node = head;
        while (node != nullptr)
        {
            size++;
            node = node->next;
        }
        return size;
    }
};



int main()
{
    LinkedList list;
    cout << list.Empty() << endl;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);
    list.addLast(-1);
    list.addLast(-2);
    list.addLast(-3);

    list.Print();

    list.removeFirst();
    cout << "\nHead data: " << list.head->data << endl;
    list.Print();

    list.removeFirst();
    cout << "\nHead data: " << list.head->data << endl;
    list.Print();

    cout << endl;
    cout << "Removing data" << endl;
    list.removeLast();

    list.Print();

    
    cout << "\nSize: " << list.size();
    cout << "\nEmpty now: " << list.Empty();
}
