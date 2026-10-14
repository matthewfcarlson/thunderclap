// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0028c0b0 @ 0x0028c0b0
// 0x0028c0b0: quaternion channel constructor holding 16-byte elements, allocated from the parent pool or the heap
extern char DAT_0042ca2c[];
void* __cdecl FUN_0008d6d0(unsigned size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_00011450;

struct Pool {
    void* FUN_002888c0(int size, int tag);
};

class QuaternionChannel {
public:
    int vptr;
    int field_04;
    int field_08;
    Pool* parent;
    int count;
    int field_14;
    void* data;
    QuaternionChannel* FUN_0028b420(int a, int b);
    QuaternionChannel* Construct(int a, int b);
};

QuaternionChannel* QuaternionChannel::Construct(int a, int b)
{
    FUN_0028b420(a, b);
    vptr = (int)DAT_0042ca2c;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 16);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 16, n, &FUN_00011450);
        data = mem;
        return this;
    }
    data = parent->FUN_002888c0(count * 16, 3);
    return this;
}
