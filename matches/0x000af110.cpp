extern void* g_vftable[];
extern "C" void* memset(void*, int, unsigned int);
class Arg {
  public:
    virtual void V0();
};
class Ctl {
  public:
    void* vptr;
    Ctl* m4;
    Arg* m8;
    int arr[0x29];
    Ctl* ctor(Arg* a);
};
Ctl* Ctl::ctor(Arg* a) {
    m4 = 0;
    vptr = g_vftable;
    m8 = a;
    a->V0();
    memset(arr, 0, 0xa4);

    return this;
}
