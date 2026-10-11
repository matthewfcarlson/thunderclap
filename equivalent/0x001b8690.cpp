// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001b8690 @ 0x001b8690
struct Child {
    virtual void vfn0();
    Child *FUN_00294880();
    void FUN_00293e40(int a, int b, int c, int d);
    void FUN_00293e90(unsigned int c);
    char pad[0x20 - 4];
    unsigned int color;
    char pad2[0x2c - 0x24];
    unsigned int mask;
    char pad3[0x140 - 0x30];
};
extern void *__cdecl FUN_0008d690(unsigned int n);

class Owner {
public:
    void FUN_001b8690();
    int pad0;
    Child *child;
    int v[4];
};

void Owner::FUN_001b8690()
{
    Child *c = (Child *)FUN_0008d690(0x140);
    if (c)
        c = c->FUN_00294880();
    child = c;
    c->vfn0();
    child->FUN_00293e40(v[0], v[1], v[2], v[3]);
    child->color = 0xff000000;
    child->mask = 0xffffffff;
    child->FUN_00293e90(0xff000000);
}
