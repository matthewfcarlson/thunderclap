// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00222230 @ 0x00222230
struct Sub40 {
    char pad0[0x10];
    void FUN_0022b650(struct Xform* dst);
};

struct Xform {
    char pad0[0x40];
    Sub40 sub;          // 0x40
    int mode;           // 0x50
    void FUN_0022c120();
    void FUN_0022c2b0(void* a, void* b);
    void FUN_00222230(void* a, void* b);
};

void Xform::FUN_00222230(void* a, void* b)
{
    Xform local = *this;
    if (mode == 1) {
        local.sub.FUN_0022b650(&local);
        local.mode = 0;
    }
    local.FUN_0022c120();
    local.mode = 2;
    local.FUN_0022c2b0(a, b);
}
