struct Node {
    Node* next;
};
struct List_25d640 {
    Node* head;
    Node* tail;
};
extern "C" void FUN_0025d640(void * list, void * item) {
    Node* target = (Node*)((char*)((Node *)item) + 4);
    Node* prev = 0;
    Node* cur = ((List_25d640 *)list)->head;
    if (cur != target) {
        do {
            prev = cur;
            cur = cur->next;
        } while (cur != target);
    }
    if (prev == 0)
        ((List_25d640 *)list)->head = target->next;
    else
        prev->next = target->next;
    if (target->next == 0)
        ((List_25d640 *)list)->tail = prev;
}