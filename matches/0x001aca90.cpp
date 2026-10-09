extern void* __cdecl Allocate(unsigned int);
class Thing {
  public:
    void Init(int);
};
class Sub {
  public:
    void Finish();
};
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
};
void* Factory::v5() {
    Thing* p = (Thing*)Allocate(24);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = 0x41d48c;
        *(unsigned int*)((char*)p + 12) = 0;
        ((Sub*)((char*)p + 16))->Finish();
        return p;
    }
    return 0;
}