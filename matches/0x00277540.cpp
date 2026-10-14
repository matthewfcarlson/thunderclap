class Node {
  public:
    virtual void f0();
    virtual void f1();
    char pad[0x64 - 4];
    Node* next;
};
class Owner_277540 {
  public:
    Node* head[2];
};
void __fastcall FUN_00277540(Owner_277540* self) {
    for (unsigned int i = 0; i < 2; ++i) {
        Node* p = self->head[i];
        while (p) {
            Node* c = p;
            p = c->next;
            c->f1();
        }
    }
}
