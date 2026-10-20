// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028bf20 @ 0x0028bf20
// 0x0028bf20: channel constructor holding 12-byte elements, allocated from the parent pool or the heap
extern char DAT_0042c9f0[];
void* __cdecl FUN_0008d6d0(unsigned size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_00011090;

struct Pool_28bf20 {
    void* FUN_002888c0(int size, int tag);
};

class Vector3DOFChannel_28bf20 {
public:
    int vptr;
    int field_04;
    int field_08;
    Pool_28bf20* parent;
    int count;
    int field_14;
    void* data;
    Vector3DOFChannel_28bf20* FUN_0028b420(int a, int b);
    Vector3DOFChannel_28bf20* Construct(int a, int b);
};

Vector3DOFChannel_28bf20* Vector3DOFChannel_28bf20::Construct(int a, int b)
{
    FUN_0028b420(a, b);
    vptr = (int)DAT_0042c9f0;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 12);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 12, n, &FUN_00011090);
        data = mem;
        return this;
    }
    data = parent->FUN_002888c0(count * 12, 3);
    return this;
}
