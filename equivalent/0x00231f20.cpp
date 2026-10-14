// STATUS: equivalent (tools/equiv.py level 3: 2742 inputs, branch coverage 10/10)
// FUN_00231f20 @ 0x00231f20
int __cdecl FUN_00238190(int a);
int __cdecl FUN_00266da0(int a);
struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int a, int b);
    char pad04[4];
    Node *next;
    unsigned int flags;
    char pad10[8];
    int f18;
    void FUN_00232600(int a, int b);
};
struct Target {
    char pad0[0x20];
    Node *head;
    void FUN_00231f20(int arg);
};
void Target::FUN_00231f20(int arg)
{
    int h = FUN_00266da0(FUN_00238190(3));
    for (Node *n = head; n != 0; n = n->next) {
        unsigned int f = n->flags;
        if (((f >> 2) & 1) && !((f >> 3) & 1)) {
            if (!n->v5(arg, n->f18))
                n->FUN_00232600(8, 1);
        }
    }
    FUN_00266da0(h);
}
