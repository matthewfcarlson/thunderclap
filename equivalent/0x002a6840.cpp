// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 8/8)
// FUN_002a6840 @ 0x002a6840
struct Ent {
    char pad0[0x4c];
    int f50;
    char pad1[0x5c - 0x54];
    int f5c;
    char pad2[0x68 - 0x60];
    int f68;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5();
};
struct Slot { Ent *ent; int pad[3]; };
struct Group { char pad[0x48]; Slot *begin; Slot *end; };
struct Target {
    char pad0[0x44];
    Group *group;
    int pad48;
    int *values;
    void (__cdecl *callback)(Target *self, int val, int a, int b, int c);
    void FUN_002a6840();
};
void Target::FUN_002a6840()
{
    int n = group->end - group->begin;
    if (n == 0)
        return;
    do {
        Ent *e = group->begin[n - 1].ent;
        n--;
        if (e != 0) {
            int saved = e->f50;
            int v;
            if (e->v5() < 0)
                v = e->f5c;
            else
                v = e->f68;
            callback(this, values[n], v, saved, 0);
        }
    } while (n != 0);
}
