class CementLibrary {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad[0x10];
};
void CementLibrary::vfunc_0() {
    struct Sub {
        virtual void first();
        virtual void second();
        int count;
    };
    Sub* p = (Sub*)((char*)this + 0x10);
    p->first();
    ++p->count;
    p->second();
}