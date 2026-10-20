// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 5/6, incomplete)
// FUN_001c5960 @ 0x001c5960
void *__cdecl FUN_0008d690(unsigned int size);

class Object_1c5960 {
public:
    virtual void v0();
    char pad4[4];
    char sub8[1];
    char pad9[0xb0 - 9];
    Object_1c5960 *FUN_001c4eb0(int a, int b);
    char FUN_001c4af0();
};

class SubList {
public:
    void FUN_001c7870(void *a, Object_1c5960 *b);
};

class Mgr_1c5960 {
public:
    char pad0[8];
    SubList list;
    char pad_c[0x248 - 8 - 1];
    Object_1c5960 *f248;
    Object_1c5960 *FUN_001c5960(int a, int b);
};

Object_1c5960 *Mgr_1c5960::FUN_001c5960(int a, int b)
{
    void *mem = FUN_0008d690(0xb0);
    if (mem == 0)
        return 0;
    Object_1c5960 *n = ((Object_1c5960 *)mem)->FUN_001c4eb0(a, b);
    if (n == 0)
        return n;
    n->v0();
    list.FUN_001c7870(n->sub8, n);
    if (n->FUN_001c4af0())
        f248 = n;
    return n;
}
