struct Node {
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
void FUN_0025d640(List* list, Node* item) {
    Node* target = (Node*)((char*)item + 4);
    Node* prev = 0;
    Node* cur = list->head;
    if (cur != target) {
        do {
            prev = cur;
            cur = cur->next;
        } while (cur != target);
    }
    if (prev == 0)
        list->head = target->next;
    else
        prev->next = target->next;
    if (target->next == 0)
        list->tail = prev;
}