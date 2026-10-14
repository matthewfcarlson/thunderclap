// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c5960 @ 0x001c5960
void *__cdecl FUN_0008d690(unsigned int size);

class Node {
public:
    virtual void v0();
    char pad4[4];
    char sub8[1];
    char pad9[0xb0 - 9];
    Node *FUN_001c4eb0(int a, int b);
    char FUN_001c4af0();
};

class SubList {
public:
    void FUN_001c7870(void *a, Node *b);
};

class Mgr_1c5960 {
public:
    char pad0[8];
    SubList list;
    char pad_c[0x248 - 8 - 1];
    Node *f248;
    Node *FUN_001c5960(int a, int b);
};

Node *Mgr_1c5960::FUN_001c5960(int a, int b)
{
    void *mem = FUN_0008d690(0xb0);
    if (mem == 0)
        return 0;
    Node *n = ((Node *)mem)->FUN_001c4eb0(a, b);
    if (n == 0)
        return n;
    n->v0();
    list.FUN_001c7870(n->sub8, n);
    if (n->FUN_001c4af0())
        f248 = n;
    return n;
}
