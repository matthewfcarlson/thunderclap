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
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void vfunc_29(unsigned int*, unsigned int*, unsigned int*, unsigned int*);
    char pad[0x48 - sizeof(void*)];
    void* mData;
};
void pddiBaseContext::vfunc_29(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* d) {
    *a = *(unsigned int*)((char*)mData + 0x24);
    *b = *(unsigned int*)((char*)mData + 0x28);
    *c = *(unsigned int*)((char*)mData + 0x2c);
    *d = *(unsigned int*)((char*)mData + 0x30);
}
} // namespace pure3d