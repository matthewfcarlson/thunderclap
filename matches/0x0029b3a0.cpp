typedef unsigned char u8;
typedef unsigned int u32_29b3a0;
void ReleaseThing(void* p);
class Base_29b3a0 {
  public:
    virtual void f0();
    virtual void f1();
};
class TextString {
  public:
    virtual void f0();
    virtual void f1();
    virtual ~TextString();
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
    char pad[0x3c];
    Base_29b3a0* mBase;
    char p44[4];
    u32_29b3a0 mThing;
    char p4c[4];
    u8 mFlag;
    void cleanup();
};
TextString::~TextString() {
    if (mFlag)
        ReleaseThing((void*)mThing);
    mBase->f1();
    mBase = 0;
    cleanup();
}
