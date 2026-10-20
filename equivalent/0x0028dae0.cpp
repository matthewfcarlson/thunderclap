// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0028dae0 @ 0x0028dae0
void *__cdecl FUN_0008d6d0(unsigned int size);
void __stdcall FUN_00011520(void *base, unsigned int size, int count, void *ctor);
extern char FUN_00289ef0;

struct SharedPool {
    void *FUN_002888c0(int size, int stride);
};

class ChannelBase {
public:
    ChannelBase(int a, int b) throw();
    virtual void v0();

    char pad04[8];
    SharedPool *shared;  // +0x0c
    int count;           // +0x10
    int pad14;
};

// equiv-map: ??0ChannelBase@@QAE@HH@Z = 0x0028b420
class CompressedQuaternionChannel : public ChannelBase {
public:
    CompressedQuaternionChannel(int a, int b);
    virtual void v0();

    void *data;          // +0x18
};

// Allocates (or borrows from the shared pool) 3 bytes per element.
CompressedQuaternionChannel::CompressedQuaternionChannel(int a, int b) : ChannelBase(a, b) {
    data = 0;
    if (shared == 0) {
        int n = count;
        void *mem = FUN_0008d6d0(n * 3);
        if (mem != 0) {
            FUN_00011520(mem, 3, n, &FUN_00289ef0);
            data = mem;
        } else {
            data = 0;
        }
    } else {
        data = shared->FUN_002888c0(count * 3, 3);
    }
}
