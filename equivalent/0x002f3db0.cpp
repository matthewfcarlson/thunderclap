// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3db0 @ 0x002f3db0
struct Rec { int w[6]; Rec* FUN_00298530(void* a, void* b); };
struct Inner { char pad[0x24]; Rec rec; };
struct Obj {
    char pad0[0x44]; Inner* inner;
    char pad1[0xcc - 0x48]; char flag;
    Rec Get();
};
Rec Obj::Get() {
    if (flag) {
        Rec tmp;
        tmp.FUN_00298530((char*)this + 0x4c, &inner->rec);
        return tmp;
    }
    return inner->rec;
}
