// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 2/2)
// FUN_001c7770 @ 0x001c7770
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
extern void __cdecl thunk_FUN_00267090(void* p);
extern void* __cdecl FUN_0008d690(unsigned int size);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct IntArray {
    char pad00[8];
    unsigned int capacity;   // 0x08
    char pad0c[4];
    unsigned int count;      // 0x10
    int* data;               // 0x14
    void Reserve(unsigned int newCapacity);
};

void IntArray::Reserve(unsigned int newCapacity)
{
    int* fresh = static_cast<int*>(FUN_0008d690(newCapacity << 2));
    memset(fresh, 0, newCapacity << 2);
    if (data != 0)
        memcpy(fresh, data, count * 4 + 4);
    capacity = newCapacity;
    thunk_FUN_00267090(data);
    data = fresh;
}
