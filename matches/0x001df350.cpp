class Obj {
    char pad[0x194];

  public:
    unsigned char flag;
};
Obj* __stdcall lookup(int);
unsigned char __stdcall FUN_001df350(int id) {
    Obj* p = lookup(id);
    unsigned char r = 0;
    if (p)
        r = p->flag;
    return r;
}