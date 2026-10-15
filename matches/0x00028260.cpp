struct Obj {
    char pad[0x20a8];
    int value;
};
struct Thing {
    int Get(int);
    Obj* Find(__int64);
};
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
int Thing::Get(int a) {
    __int64 v = FUN_002672f0(a, 0, 0);
    Obj* p = Find(v);
    if (!p)
        return 0;
    return p->value;
}