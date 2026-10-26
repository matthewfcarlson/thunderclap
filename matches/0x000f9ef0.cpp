#include "decls/data/game/DollyScript.h"
// data: g_val = DAT_004e0a08

struct Result_f9ef0 {
    virtual void pad();
    virtual long long Get();
};
struct Node {
    void* vptr;
    Node* next;
    int count;
};
struct Head_f9ef0 {
    int pad;
    Node* first;
};
struct Owner_f9ef0 {
    char pad[8];
    Head_f9ef0* head;
};
bool __fastcall FUN_000f9ef0(Owner_f9ef0* self) {
    Head_f9ef0* h = self->head;
    if (h) {
        Node* n = h->first;
        while (n) {
            if (n->count <= 1) {
                long long v = ((Result_f9ef0*)n)->Get();
                if (v == (*(long long*)&DAT_004e0a08))
                    return true;
                return false;
            }
            n = n->next;
        }
    }
    return false;
}
