struct Node {
    char pad[0x20];
    Node* next;
};
class Obj {
  public:
    char pad[0x1c];
    Node* head;
    int Count();
};
int Obj::Count() {
    Node* p = head;
    int n = 0;
    while (p) {
        p = p->next;
        ++n;
    }
    return n;
}