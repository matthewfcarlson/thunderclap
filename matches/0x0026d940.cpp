#include "decls/data/platform/xbox/core.h"

struct Node {
    Node* next;
    Node* previous;
};

extern void(__stdcall* DAT_003f2c8c)(void*);
extern void(__stdcall* DAT_003f2c88)(void*);

void __cdecl FUN_0026d940(Node* node) {
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if (node->previous == 0)
        (*(Node**)&DAT_0052a180) = node->next;
    else
        node->previous->next = node->next;
    if (node->next == 0)
        (*(Node**)&DAT_0052a17c) = node->previous;
    else
        node->next->previous = node->previous;
    DAT_003f2c88(((char*)&DAT_0052a188));
}