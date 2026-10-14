extern "C" char DAT_0041d40c[];
class Event_1ac740 {
  public:
    void Init(int);
};
void* __cdecl Alloc(unsigned int);
class Factory_1ac740 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Event_1ac740* Make();
};
Event_1ac740* Factory_1ac740::Make() {
    Event_1ac740* p = (Event_1ac740*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((int)DAT_0041d40c);
        *((unsigned char*)p + 0xc) = 1;
        return p;
    }
    return 0;
}