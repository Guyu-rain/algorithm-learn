#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {} // 构造函数
};

ListNode* createLinkedList(std::vector<int> arr)
{
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode*cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = createLinkedList({1, 2, 3, 4, 5});
    printList(head);
    // 增
    // (1)头插 - O(1)
    ListNode* newNode1 = new ListNode(0);
    newNode1->next = head;
    head = newNode1;
    printList(head);

    // (2)尾插 - O(n)
    ListNode* p1 = head;
    while(p1->next != nullptr) { // p是最后一个节点，`p->next == nullptr`
        p1 = p1->next;
    }
    p1->next = new ListNode(6);
    printList(head);

    // (3)中间任意位置插入 - O(n)
    ListNode* p2 = head;
    int idx = 2;
    for (int i = 0; i < idx; i++) {
        p2 = p2->next;
    }
    ListNode* newNode2 = new ListNode(66);
    newNode2->next = p2->next;
    p2->next = newNode2;
    printList(head);

    // 删除（这里不考虑内存释放）
    // 尾删 - O(n)
    ListNode* p3 = head;
    while(p3->next->next != nullptr) {
        p3 = p3->next;
    }
    p3->next = nullptr;
    printList(head);

    // 头删 - O(1)
    head = head->next;


    // 删除中间一个元素 - O(n)
    ListNode* p4 = head;
    idx = 2;
    

    return 0;
}