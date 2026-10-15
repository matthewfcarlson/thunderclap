struct Item {
    char pad[0x394];
    int field;
};
struct Obj {
    Item* Find(__int64 v);
    Item* Get(unsigned a, unsigned b);
};
extern "C" __int64 __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
Item* Obj::Get(unsigned a, unsigned b) {
    __int64 v = FUN_002672f0(a, 0, 0);
    Item* p = Find(v);
    if (p)
        p->field = b;
    return p;
}