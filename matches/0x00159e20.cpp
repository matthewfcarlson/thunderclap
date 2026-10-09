extern "C" void* __cdecl Alloc(unsigned int);
class TrackBase {
  public:
    void Init();
};
class TrackFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual char* F();
};
char* TrackFactoryTemplate::F() {
    char* p = (char*)Alloc(0x18);
    if (p) {
        ((TrackBase*)p)->Init();
        *(int*)p = 0x414330;
        *(int*)(p + 0xc) = 0;
        *(int*)(p + 0x10) = (int)0xbf800000;
        *(int*)(p + 0x14) = 0;
        *(int*)(p + 8) = 1;
        return p;
    }
    return 0;
}