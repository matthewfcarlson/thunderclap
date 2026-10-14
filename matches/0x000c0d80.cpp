extern "C" char DAT_003fef7c[];
struct Obj_c0d80 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(void*, unsigned long long);
};
extern unsigned long long Get(void*);
void Target(Obj_c0d80* p, int b) {
    unsigned long long x = Get((void*)b);
    struct Local {
        void* v;
    };
    Local local;
    local.v = (void*)((int)DAT_003fef7c);
    p->f3(&local, x);
}
