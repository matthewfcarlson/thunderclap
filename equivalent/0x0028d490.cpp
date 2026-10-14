// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0028d490 @ 0x0028d490
// 0x0028d490: channel constructor holding 6-byte elements, allocated from the parent pool or the heap
extern char DAT_0042cac8[];
void* __cdecl FUN_0008d6d0(unsigned size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_001db770;

struct Pool_28d490 {
    void* FUN_002888c0(int size, int tag);
};

class Channel {
public:
    int vptr;
    int field_04;
    int field_08;
    Pool_28d490* parent;
    int count;
    int field_14;
    void* data;
    Channel* FUN_0028b420(int a, int b);
    Channel* Construct(int a, int b);
};

Channel* Channel::Construct(int a, int b)
{
    FUN_0028b420(a, b);
    vptr = (int)DAT_0042cac8;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 6);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 6, n, &FUN_001db770);
        data = mem;
        return this;
    }
    data = parent->FUN_002888c0(count * 6, 3);
    return this;
}
