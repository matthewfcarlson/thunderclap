class SeqEventContainer {
  public:
    char pad[0x14];
};
class SeqEventCondition : public SeqEventContainer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventCondition* vfunc_4(unsigned char);
    virtual void v5();
};
class A {
  public:
    void f();
};
class B {
  public:
    void f();
};
void __cdecl f47550(void*, SeqEventCondition*);
extern char gBss;
SeqEventCondition* SeqEventCondition::vfunc_4(unsigned char flag) {
    ((A*)((char*)this + 0x14))->f();
    ((B*)this)->f();
    if (flag & 1)
        f47550(&gBss, this);
    return this;
}