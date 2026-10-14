struct Node {
    virtual void F(int);
    Node* next;
};
void thunk_FUN_00267090(int);
struct Obj_f9a80 {
    Node* head;
    int value;
};
void __fastcall FUN_000f9a80(Obj_f9a80* self) {
    Node* p = self->head;
    while (p) {
        Node* n = p->next;
        p->F(1);
        p = n;
    }
    thunk_FUN_00267090(self->value);
}