// STATUS: equivalent (tools/equiv.py level 3: 41 inputs, branch coverage 6/6)
// FUN_00270020 @ 0x00270020
struct Pool_270020 {
    char pad0[0x10];
    void* freeHead;
    void* owner;
    void* blocks;
    unsigned stride;
    unsigned count;
    unsigned flags;
    unsigned zero28;
    unsigned zero2c;
    unsigned zero30;
    void FUN_00270020(void* buffer, unsigned itemSize, unsigned itemCount, unsigned flagsValue, void* allocator, unsigned unused6, unsigned itemAdjustment);
};
extern "C" unsigned __cdecl FUN_0026fd50(unsigned, unsigned);
extern "C" void* __cdecl FUN_00266eb0(void*, unsigned, unsigned);
void Pool_270020::FUN_00270020(void* buffer, unsigned itemSize, unsigned itemCount, unsigned flagsValue, void* allocator, unsigned unused6, unsigned itemAdjustment) {
    stride = FUN_0026fd50(itemSize, itemAdjustment);
    count = itemCount;
    flags = flagsValue;
    zero28 = 0;
    zero2c = 0;
    owner = allocator;
    zero30 = 0;
    void* base;
    if (buffer == 0)
        base = FUN_00266eb0(allocator, stride * itemCount, 4);
    else
        base = (void*)FUN_0026fd50((unsigned)buffer, 4);
    blocks = base;
    freeHead = 0;
    char* ptr = (char*)base;
    for (unsigned i = 0; i < count; ++i) {
        *(void**)ptr = freeHead;
        freeHead = ptr;
        ptr += stride;
    }
}
