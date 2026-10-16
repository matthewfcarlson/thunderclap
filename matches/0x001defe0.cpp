struct Obj {
    char pad[0xa8];
    char flag;
};
struct Holder {
    char pad[0x11c];
    Obj* obj;
};
Holder* __stdcall get(int);
void __stdcall FUN_001defe0(int id, char v) {
    Holder* h = get(id);
    if (h) {
        Obj* o = h->obj;
        if (o)
            o->flag = v;
    }
}