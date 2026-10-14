struct Obj {
    char pad[0xcd];
    char flag;
};

Obj* __stdcall Helper(void*);

void __stdcall FUN_001fcc40(void* p) {
    Obj* r = Helper(p);
    if (r) {
        r->flag = 0;
    }
}
