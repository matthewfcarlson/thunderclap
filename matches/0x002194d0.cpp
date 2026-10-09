struct Owner; struct Result { unsigned char pad[16]; };
Result* __cdecl Create(Owner*, int, int, void*);
struct Node { unsigned char pad[0x14]; unsigned char flag; unsigned char pad2[7]; int* slot; };
struct Owner { unsigned char pad[0x10]; Node* node; };
void __cdecl FUN_002194d0(Owner* p, Result* x) {
    Result* r = Create(p, 0, 0, (char*)x + 0x10);
    r->pad[5] = p->node->flag;
    *(Result**)(r->pad + 12) = x;
    r->pad[4] = 7;
    *(int*)(r->pad + 8) = 0;
    *(int*)r->pad = *p->node->slot;
    *p->node->slot = (int)r;
}
