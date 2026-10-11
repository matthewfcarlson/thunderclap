extern "C" char DAT_003f6098[];
void thunk(void*);
struct Obj {
    int pad;
    void* vf;
    Obj* f(unsigned char flags);
};
Obj* Obj::f(unsigned char flags) {
    Obj* self = this;
    volatile void** p;
    if (self)
        p = (volatile void**)((char*)self + 4);
    else
        p = 0;
    *p = (void*)((int)DAT_003f6098);
    if (flags & 1)
        thunk(self);
    return self;
}