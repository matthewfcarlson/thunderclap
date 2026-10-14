struct Obj_1fcc40 {
    char pad[0xcd];
    char flag;
};

Obj_1fcc40* __stdcall Helper(void*);

void __stdcall FUN_001fcc40(void* p) {
    Obj_1fcc40* r = Helper(p);
    if (r) {
        r->flag = 0;
    }
}
