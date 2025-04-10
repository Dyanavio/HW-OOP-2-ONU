#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) return nullptr;

        int value = head->val;
        ListNode* sorted = new ListNode(value);
        //head->next == nullptr ? sorted->next = nullptr : sorted->next = new ListNode();

        ListNode* tempSort = sorted;
        ListNode* temp = head->next;

        while (temp != nullptr)
        {
            if (value != temp->val)
            {
                value = temp->val;
                tempSort->next = new ListNode(value);
                tempSort = tempSort->next;

            }
            temp = temp->next;
        }
        return sorted;
    }

};


void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Create two sorted linked lists: 1 -> 3 -> 5 and 2 -> 4 -> 6
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(1);


    ListNode* sortedList = solution.deleteDuplicates(list1);

    cout << "Merged List: ";
    printList(sortedList);

    return 0;
}
