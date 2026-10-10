// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026ca80 @ 0x0026ca80
namespace core {
struct IMemoryAllocator { virtual void slot0(); };
struct Object { virtual void slot0(); Object(); };
struct MemoryDlAllocator : IMemoryAllocator, Object {
    int initial;
    int start;
    int end;
    int size;
    int current;
    unsigned char data[0x474];
    int a, b, c;
    unsigned char flag, disabled;
    unsigned char pad[2];
    int d;
    MemoryDlAllocator(int, int, int);
};
}
extern int DAT_004cdbb0;
void __cdecl FUN_002705f0();
int __cdecl FUN_00266e00(int, int);
core::Object::Object() {
    core::MemoryDlAllocator* owner = (core::MemoryDlAllocator*)((char*)this - 4);
    owner->initial = DAT_004cdbb0;
    FUN_002705f0();
}
core::MemoryDlAllocator::MemoryDlAllocator(int amount, int other, int unused) {
    a = b = c = 0;
    flag = 1;
    disabled = 0;
    d = 0;
    FUN_002705f0();
    size = amount;
    int result = FUN_00266e00(other, amount);
    start = result;
    current = result;
    end = size + result;
    for (int i = 0; i < 0x11d; ++i)
        ((int*)data)[i] = 0;
}
