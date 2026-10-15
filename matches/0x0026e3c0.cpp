struct Node {
    char pad[16];
    Node* next;
};
class Obj {
    char pad[0x1d4];
    Node* head;

  public:
    void Remove(Node* node);
    void Empty();
};
void Obj::Remove(Node* node) {
    Node** p = &head;
    if (*p) {
        do {
            if (*p == node) {
                *p = (*p)->next;
                break;
            }
            p = &(*p)->next;
        } while (*p);
    }
    if (!head)
        Empty();
}