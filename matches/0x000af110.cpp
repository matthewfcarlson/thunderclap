extern void* g_vftable_af110[];
extern "C" void* memset(void*, int, unsigned int);
class Arg_af110 {
  public:
    virtual void V0();
};
class Ctl_af110 {
  public:
    void* vptr;
    Ctl_af110* m4;
    Arg_af110* m8;
    int arr[0x29];
    Ctl_af110* ctor(Arg_af110* a);
};
Ctl_af110* Ctl_af110::ctor(Arg_af110* a) {
    m4 = 0;
    vptr = g_vftable_af110;
    m8 = a;
    a->V0();
    memset(arr, 0, 0xa4);

    return this;
}
