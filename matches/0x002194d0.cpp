#include "compat/ptr.h"
struct Owner_2194d0;
struct Result_2194d0 {
    unsigned char pad[16];
};
Result_2194d0* __cdecl Create(Owner_2194d0*, int, int, void*);
struct Node {
    unsigned char pad[0x14];
    unsigned char flag;
    unsigned char pad2[7];
    int* slot;
};
struct Owner_2194d0 {
    unsigned char pad[0x10];
    Node* node;
};
extern "C" void * __cdecl FUN_002194d0(void * p, void * x) {
    Result_2194d0* r = Create(((Owner_2194d0 *)p), 0, 0, (char*)((Result_2194d0 *)x) + 0x10);
    r->pad[5] = ((Owner_2194d0 *)p)->node->flag;
    *(Result_2194d0**)(r->pad + 12) = ((Result_2194d0 *)x);
    r->pad[4] = 7;
    *(int*)(r->pad + 8) = 0;
    *(int*)r->pad = *((Owner_2194d0 *)p)->node->slot;
    *(hulk_intptr*)((Owner_2194d0 *)p)->node->slot = (hulk_intptr)r;
    return (Result_2194d0 *)r;
}
