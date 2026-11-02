#include "decls/data/platform/xbox/core.h"

struct Node {
    Node* next;
    Node* previous;
};

extern void(__stdcall* DAT_003f2c8c)(void*);
extern void(__stdcall* DAT_003f2c88)(void*);

extern "C" void __cdecl FUN_0026d940(void * node) {
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if (((Node *)node)->previous == 0)
        (*(Node**)&DAT_0052a180) = ((Node *)node)->next;
    else
        ((Node *)node)->previous->next = ((Node *)node)->next;
    if (((Node *)node)->next == 0)
        (*(Node**)&DAT_0052a17c) = ((Node *)node)->previous;
    else
        ((Node *)node)->next->previous = ((Node *)node)->previous;
    DAT_003f2c88(((char*)&DAT_0052a188));
}