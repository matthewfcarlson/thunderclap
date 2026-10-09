namespace pure3d {
class pddiBaseContext {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(void*);
    char pad[0x48 - 4];
    void* member;
};
void pddiBaseContext::vfunc_8(void* p) {
    *(void**)((char*)member + 8) = p;
}
} // namespace pure3d