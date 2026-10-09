struct Result {
    virtual void pad();
    virtual long long Get();
};
struct Node {
    void* vptr;
    Node* next;
    int count;
};
struct Head {
    int pad;
    Node* first;
};
struct Owner {
    char pad[8];
    Head* head;
};
extern long long g_val;
bool __fastcall FUN_000f9ef0(Owner* self) {
    Head* h = self->head;
    if (h) {
        Node* n = h->first;
        while (n) {
            if (n->count <= 1) {
                long long v = ((Result*)n)->Get();
                if (v == g_val)
                    return true;
                return false;
            }
            n = n->next;
        }
    }
    return false;
}
