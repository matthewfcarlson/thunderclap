namespace core {
class TimerList;
struct Timer {
    unsigned fun(TimerList*, unsigned, unsigned, unsigned, unsigned, unsigned);
};
struct Source {
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual Timer* get();
};
class TimerList {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(unsigned*, unsigned, unsigned, unsigned, unsigned, unsigned);
    char pad[20];
    Source* source;
};
void TimerList::vfunc_3(unsigned* result, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) {
    Timer* timer = source->get();
    *result = timer ? timer->fun(this, a, b, c, d, e) : 0;
}
} // namespace core