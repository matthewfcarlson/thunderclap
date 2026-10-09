class Node {
  public:
    char pad[16];
    Node* next;
};
class List {
  public:
    Node* head;
    Node* Get(int index);
};
Node* List::Get(int index) {
    int i = 0;
    Node* p = head;
    while (p != 0 && index >= i) {
        if (index == i)
            return p;
        p = p->next;
        i++;
    }
    return 0;
}
