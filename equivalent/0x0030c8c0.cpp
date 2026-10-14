// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0030c8c0 @ 0x0030c8c0
class Obj_30c8c0 {
public:
    char pad0[0xf8];
    char b0;
    int a[0x15];     // 0xfc..0x150 (22 dwords up to 0x14c)
    char c0;         // 0x150
    char c1;         // 0x151
    char pad152[2];
    int d0;          // 0x154
    int d1;          // 0x158
    void FUN_0030c690(Obj_30c8c0 *src);
    Obj_30c8c0 *FUN_0030c8c0(Obj_30c8c0 *src);
};

Obj_30c8c0 *Obj_30c8c0::FUN_0030c8c0(Obj_30c8c0 *src)
{
    FUN_0030c690(src);
    b0 = src->b0;
    for (int i = 0; i < 0x15; i++)
        a[i] = src->a[i];
    c0 = src->c0;
    c1 = src->c1;
    d0 = src->d0;
    d1 = src->d1;
    return this;
}
