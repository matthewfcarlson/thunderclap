#include "decls/data/platform/xbox/core.h"
// data: gSpecial = DAT_0052a138

extern void __stdcall DeleteFiber(void*);
struct Node {
    char pad[8];
    Node* parent;
    Node* prev;
    Node* next;
    void* fiber;
};
extern "C" void __cdecl FUN_0026d7a0(void * p) {
    if (((Node *)p) != (Node*)&(*(int*)((char*)&DAT_0052a130 + 8)) && ((Node *)p) != (Node*)((char*)((Node *)p)->parent + 8))
        DeleteFiber(((Node *)p)->fiber);
    Node* parent = ((Node *)p)->parent;
    if (((Node *)p)->next == 0)
        *(Node**)((char*)parent + 0x30) = ((Node *)p)->prev;
    else
        *(Node**)((char*)((Node *)p)->next + 0x0c) = ((Node *)p)->prev;
    if (((Node *)p)->prev == 0) {
        *(Node**)((char*)parent + 0x34) = ((Node *)p)->next;
        return;
    }
    *(Node**)((char*)((Node *)p)->prev + 0x10) = ((Node *)p)->next;
}