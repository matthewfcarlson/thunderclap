class Node {
  public:
    virtual void Release(int);
    char pad[4];
    Node* next;
};
class Owner_1ef220 {
  public:
    char pad[0x10];
    Node* head;
    void Finish();
};
void __fastcall target(Owner_1ef220* self) {
    Node* n = self->head;
    while (n) {
        Node* c = n;
        n = c->next;
        c->Release(1);
    }
    self->Finish();
}
