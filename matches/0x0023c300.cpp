struct Node {
    char pad0[0x10];
    int type;
    char pad14[0x14];
    Node* next;
};
struct Owner {
    char pad0[0x28];
    Node* first;
};
Node* __fastcall target(Owner* self) {
    Node* p = self->first;
    int n = 0;
    if (p != 0) {
        do {
            if (p->type != 4)
                return p;
            ++n;
            if (n > 0x100 || p == (Node*)self)
                return 0;
            p = p->next;
        } while (p != 0);
    }
    return p;
}
