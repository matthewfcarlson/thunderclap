struct Obj_1fcc40 {
    char pad[0xcd];
    char flag;
};

struct ThisWrap_001fcc40 {
    Obj_1fcc40* Helper(void*);
    void FUN_001fcc40(void* p);
};

void ThisWrap_001fcc40::FUN_001fcc40(void* p) {
    Obj_1fcc40* r = this->Helper(p);
    if (r) {
        r->flag = 0;
    }
}
