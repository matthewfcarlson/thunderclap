#include "decls/data/platform/xbox/core.h"
// data: gFirst_26d8f0 = DAT_0052a180, gLast_26d8f0 = DAT_0052a17c, gLock_26d8f0 = DAT_0052a188

// the thread list (0x0026d940 unlinks, 0x0026dbb0 walks it): the node is the thread object's first two words
struct Node_26d8f0 {
    Node_26d8f0* next;
    Node_26d8f0* previous;
};
extern "C" void(__stdcall* DAT_003f2c8c)(void*);   // kernel import slot RtlEnterCriticalSection
extern "C" void(__stdcall* DAT_003f2c88)(void*);   // kernel import slot RtlLeaveCriticalSection
extern "C" void __cdecl FUN_0026d8f0(unsigned int* node_) {   // (the callers' declaration)
    Node_26d8f0* node = (Node_26d8f0*)node_;
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if ((*(Node_26d8f0**)&DAT_0052a180) == 0) {
        (*(Node_26d8f0**)&DAT_0052a180) = node;
        node->previous = 0;
    } else {
        (*(Node_26d8f0**)&DAT_0052a17c)->next = node;
        node->previous = (*(Node_26d8f0**)&DAT_0052a17c);
    }
    (*(Node_26d8f0**)&DAT_0052a17c) = node;
    node->next = 0;
    DAT_003f2c88(((char*)&DAT_0052a188));
}
