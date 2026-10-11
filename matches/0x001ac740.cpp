extern "C" char DAT_0041d40c[];
class Event {
  public:
    void Init(int);
};
void* __cdecl Alloc(unsigned int);
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Event* Make();
};
Event* Factory::Make() {
    Event* p = (Event*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((int)DAT_0041d40c);
        *((unsigned char*)p + 0xc) = 1;
        return p;
    }
    return 0;
}