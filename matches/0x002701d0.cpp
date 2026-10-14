extern "C" int sprintf(char*, const char*, ...);
extern unsigned gTag;
void* Alloc(unsigned, unsigned);
namespace core {
struct Child_2701d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void* v13();
    Child_2701d0* Init();
    void Setup(int, unsigned, unsigned, unsigned, unsigned, char*, int);
};
struct MemoryPool {
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
    virtual void* f13();
    char pad[0xc];
    unsigned* mFree;
    unsigned mA;
    unsigned mB;
    unsigned mC;
    unsigned mY;
    unsigned mD;
    unsigned mE;
    unsigned mF;
    Child_2701d0* mChild;
};
} // namespace core
void* core::MemoryPool::f13() {
    char buf[0x80];
    if (!mFree) {
        if (!mChild && mD > 0) {
            unsigned a = mA;
            gTag = a;
            void* p = Alloc(a, 0x34);
            mChild = p ? ((Child_2701d0*)p)->Init() : 0;
            if (mChild) {
                sprintf(buf, "child of %8.8X[MemoryPool]", this);
                mChild->Setup(0, mC, mD, mD, mA, buf, 1);
                mChild->v0();
            }
        }
        if (mChild)
            return mChild->v13();
        return 0;
    }
    unsigned* p = mFree;
    mFree = (unsigned*)*p;
    mE++;
    mF = mE > mF ? mE : mF;
    return p;
}