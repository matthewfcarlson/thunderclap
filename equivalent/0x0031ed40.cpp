// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 6/6)
// FUN_0031ed40 @ 0x0031ed40
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr size);
inline void* __cdecl operator new(unsigned int, void* address) { return address; }
namespace pure3d {
struct pddiViewState {
    virtual void slot0();
    char data[0x30];
};
template<class T> struct pddiStack {
    virtual void slot0();
    int capacity;
    int depth;
    T* items;
    pddiStack(int count);
};
template<> pddiStack<pddiViewState>::pddiStack(int count) {
    pddiViewState* storage = (pddiViewState*)FUN_0008d690((unsigned int)count * 0x34);
    if (storage && (int)((unsigned int)count - 1) >= 0) {
        unsigned int remaining = (unsigned int)count;
        pddiViewState* current = storage;
        do {
            new (current) pddiViewState;
            ++current;
        } while (--remaining);
    }
    capacity = count;
    items = storage;
    depth = 0;
}
}
