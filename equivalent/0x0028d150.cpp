// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0028d150 @ 0x0028d150
// 0x0028d150: channel constructor holding 8-byte elements, allocated from the parent pool or the heap
extern char DAT_0042caa8[];
void* __cdecl FUN_0008d6d0(unsigned size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_00289ed0;

struct Pool {
    void* FUN_002888c0(int size, int tag);
};

class Channel {
public:
    int vptr;
    int field_04;
    int field_08;
    Pool* parent;
    int count;
    int field_14;
    void* data;
    Channel* FUN_0028b420(int a, int b);
    Channel* Construct(int a, int b);
};

Channel* Channel::Construct(int a, int b)
{
    FUN_0028b420(a, b);
    vptr = (int)DAT_0042caa8;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 8);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 8, n, &FUN_00289ed0);
        data = mem;
        return this;
    }
    data = parent->FUN_002888c0(count * 8, 3);
    return this;
}
