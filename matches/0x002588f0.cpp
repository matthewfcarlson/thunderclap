extern "C" char DAT_004cd1a8[];
struct Type {
    virtual void f0();
    virtual void vfunc_1();
};
extern "C" void __cdecl helper(void*, Type*);
void Type::vfunc_1() {
    helper((void*)((int)DAT_004cd1a8), this);
}