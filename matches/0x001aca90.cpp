extern "C" char DAT_0041d48c[];
extern void* __cdecl Allocate(unsigned int);
class Thing_1aca90 {
  public:
    void Init(int);
};
class Sub_1aca90 {
  public:
    void Finish();
};
class Factory_1aca90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
};
void* Factory_1aca90::v5() {
    Thing_1aca90* p = (Thing_1aca90*)Allocate(24);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041d48c);
        *(unsigned int*)((char*)p + 12) = 0;
        ((Sub_1aca90*)((char*)p + 16))->Finish();
        return p;
    }
    return 0;
}