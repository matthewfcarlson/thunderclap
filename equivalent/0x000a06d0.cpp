// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000a06d0 @ 0x000a06d0
struct Obj000a06d0 {
    unsigned int words[0x35];
    char b0;
    char b1;
    Obj000a06d0* FUN_000a06d0(const Obj000a06d0* src);
};

Obj000a06d0* Obj000a06d0::FUN_000a06d0(const Obj000a06d0* src)
{
    for (int i = 0; i < 0x35; i++) {
        words[i] = src->words[i];
    }
    b0 = src->b0;
    b1 = src->b1;
    return this;
}
