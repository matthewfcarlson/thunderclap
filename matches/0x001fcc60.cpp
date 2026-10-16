struct Obj {
    char pad[0xcd];
    unsigned char flag;
};
Obj* __stdcall findObj(int);
void __stdcall FUN_001fcc60(int id) {
    Obj* p = findObj(id);
    if (p)
        p->flag = 1;
}