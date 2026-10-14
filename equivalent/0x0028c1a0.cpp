// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 10/10)
// FUN_0028c1a0 @ 0x0028c1a0
// equiv-map: ??0Channel@pure3d@@QAE@II@Z = 0x0028b420

struct Name {
    int lo, hi;
    void FUN_0027af00();
};

struct Allocator {
    Name *FUN_002888c0(unsigned int bytes, int flags);
};

void *__cdecl FUN_0008d6d0(unsigned int size);
void __stdcall FUN_00011520(void *p, unsigned int size, unsigned int count, void (Name::*ctor)());

namespace pure3d {

class Channel {
public:
    Channel(unsigned int a, unsigned int b);
    virtual void v0();
    char pad04[8];
    Allocator *alloc;       // 0xc
    unsigned int count;     // 0x10
    char pad14[4];
};

class StringChannel : public Channel {
public:
    Name *names;            // 0x18
    StringChannel(unsigned int a, unsigned int b);
    virtual void v0();
};

StringChannel::StringChannel(unsigned int a, unsigned int b) : Channel(a, b)
{
    names = 0;
    if (alloc == 0) {
        unsigned int n = count;
        unsigned int *raw = (unsigned int *)FUN_0008d6d0(n * sizeof(Name) + 4);
        Name *arr = 0;
        if (raw != 0) {
            arr = (Name *)(raw + 1);
            raw[0] = n;
            FUN_00011520(arr, sizeof(Name), n, &Name::FUN_0027af00);
        }
        names = arr;
    } else {
        names = alloc->FUN_002888c0(count * sizeof(Name), 3);
        for (unsigned int i = 0; i < count; i++) {
            Name *p = &names[i];
            if (p != 0)
                p->FUN_0027af00();
        }
    }
}

}
