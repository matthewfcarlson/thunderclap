struct Node {
    char pad[0x64];
    Node* next;
};
class Obj {
    char pad[0x10];
    Node* node;

  public:
    Node* Advance();
};
Node* Obj::Advance() {
    Node* p = node;
    if (p)
        node = p->next;
    return p;
}