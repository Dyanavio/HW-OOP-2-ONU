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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* sorted = new ListNode();
        ListNode* temp = sorted;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        if (list1 == nullptr && list2 != nullptr)
        {
            while (temp2 != nullptr)
            {
                temp->val = temp2->val;
                temp2->next == nullptr ? temp->next = nullptr : temp->next = new ListNode();
                temp = temp->next;
                temp2 = temp2->next;
            }

            return sorted;
        }
        if (list1 != nullptr && list2 == nullptr)
        {
            cout << "Second else if" << endl;
            while (temp1 != nullptr)
            {
                temp->val = temp1->val;
                temp1->next == nullptr ? temp->next = nullptr : temp->next = new ListNode();
                temp = temp->next;
                temp1 = temp1->next;
            }
            return sorted;
        }

        while (true)
        {
            if (temp1->val >= temp2->val)
            {
                temp->val = temp2->val;
                //cout << "Added temp2 value: " << temp2->val << endl;
                temp->next = new ListNode();
                temp = temp->next;
                if (temp2->next != nullptr) temp2 = temp2->next;
                else
                {
                    //cout << "Before while loop: " << temp1->val << endl;
                    while (temp1 != nullptr)
                    {
                        temp->val = temp1->val;
                        //cout << "1) " << temp->val << endl;
                        temp1->next == nullptr ? temp->next = nullptr : temp->next = new ListNode();
                        //temp->next = new ListNode();
                        temp = temp->next;
                        temp1 = temp1->next;
                    }
                    //temp = nullptr;
                    break;
                }
            }
            else if (temp1->val <= temp2->val)
            {
                temp->val = temp1->val;
                //cout << "Added temp1 value: " << temp1->val << endl;
                temp->next = new ListNode();
                temp = temp->next;
                if (temp1->next != nullptr) temp1 = temp1->next;
                else
                {
                    while (temp2 != nullptr)
                    {
                        temp->val = temp2->val;
                        //cout << "2) " << temp->val << endl;
                        temp2->next == nullptr ? temp->next = nullptr : temp->next = new ListNode();
                        //temp->next = new ListNode();
                        temp = temp->next;
                        temp2 = temp2->next;
                    }
                    //temp = nullptr;
                    break;
                }
               
            }
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
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);
    list1->next->next->next = new ListNode(10);
    list1->next->next->next->next = new ListNode(11);
    list1->next->next->next->next->next = new ListNode(12);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Merge the two lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
