extern "C" char DAT_004136d8[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Track {
  public:
    Track();
};
class Factory {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    Track* vfunc_5();
};
Track* Factory::vfunc_5() {
    Track* p = (Track*)FUN_0008d690(0x10);
    if (p) {
        p->Track::Track();
        *(int*)p = ((int)DAT_004136d8);
        *((int*)p + 3) = 0;
        return p;
    }
    return 0;
}