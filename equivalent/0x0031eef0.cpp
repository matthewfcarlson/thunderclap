// STATUS: equivalent (tools/equiv.py level 3: 1747 inputs, branch coverage 6/6)
// FUN_0031eef0 @ 0x0031eef0
void* __cdecl FUN_0008d690(unsigned int size);
void __stdcall FUN_00011520(void* array, unsigned int elementSize, int count, void* ctor);
extern char FUN_0031e490;
inline void* __cdecl operator new(unsigned int, void* address) { return address; }

namespace pure3d {
class pddiLightingState {
public:
    virtual void dummy();
    char lights[0x3e0];
    char tail[8];
    pddiLightingState() { FUN_00011520(lights, 0x7c, 8, &FUN_0031e490); }
};
template<class T> class pddiStack {
public:
    virtual void dummy();
    int capacity;
    int depth;
    T* items;
    pddiStack(int count);
};
template<> pddiStack<pddiLightingState>::pddiStack(int count)
{
    pddiLightingState* storage = (pddiLightingState*)FUN_0008d690((unsigned int)count * 0x3ec);
    if (storage && (int)((unsigned int)count - 1) >= 0) {
        unsigned int remaining = (unsigned int)count;
        pddiLightingState* current = storage;
        do {
            new (current) pddiLightingState;
            ++current;
        } while (--remaining);
    }
    capacity = count;
    items = storage;
    depth = 0;
}
}
