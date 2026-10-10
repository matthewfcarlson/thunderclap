// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026ce90 @ 0x0026ce90
extern int DAT_004cdbb0;
void __cdecl FUN_002705f0();
namespace core {
struct IMemoryAllocator { virtual void unknownAllocator(); };
struct Object { int value; Object() { value = DAT_004cdbb0; FUN_002705f0(); } virtual void unknownObject(); };
struct MemoryDlAllocator : IMemoryAllocator, Object {
    int start;
    int end;
    int size;
    int current;
    char storage[0x474];
    int a,b,c;
    unsigned char d,e;
    char pad[2];
    int f;
    MemoryDlAllocator(unsigned char mode, int base, int count, int unused);
    virtual void unknownDerived();
};
MemoryDlAllocator::MemoryDlAllocator(unsigned char mode, int base, int count, int unused) {
    a = b = c = 0;
    d = 0;
    e = mode;
    f = 0;
    FUN_002705f0();
    start = base;
    end = base + count;
    size = count;
    current = base;
    for (int i = 0; i < 0x474; ++i) storage[i] = 0;
}
}
