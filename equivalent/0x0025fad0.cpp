// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0025fad0 @ 0x0025fad0
#include "compat/ptr.h"
struct Node { char pad[0x14]; char item[0x1c]; Node* next; void FUN_0025fad0(hulk_intptr value); };
extern "C" void * __cdecl FUN_0025f670(void *, const char **);
void Node::FUN_0025fad0(hulk_intptr value) {
    if (((int)(hulk_uintptr)FUN_0025f670(&item, (const char **)(&value)))) return;
    Node* n = next;
    if (n) {
        void (Node::* volatile recurse)(hulk_intptr) = &Node::FUN_0025fad0;
        (n->*recurse)(value);
    }
}