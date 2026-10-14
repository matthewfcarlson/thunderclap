// STATUS: equivalent (tools/equiv.py level 3: 2254 inputs, branch coverage 10/10)
// FUN_0024bae0 @ 0x0024bae0
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void Release();
};
struct Slot { Obj* obj; unsigned size; int pad; };
struct Ring {
    char pad[0x40];
    Slot slots[10];
    unsigned char start;
    unsigned char count;
    unsigned char cap;
    char pad2;
    unsigned total;
};

// Pops entries off the back of the ring until `count` drops to `keep`.
void __cdecl FUN_0024bae0(Ring* r, char dropAll)
{
    int keep = (dropAll == 0);
    while (r->count > keep) {
        if (r->total != 0)
            r->total -= r->slots[(r->count + r->start - 1) % r->cap].size;
        Obj* o = r->slots[(r->start + r->count - 1) % r->cap].obj;
        if (o)
            o->Release();
        r->count--;
    }
}
