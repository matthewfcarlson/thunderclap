class TimerBase {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void vfunc_9();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct List {
    char pad[0x1c];
    unsigned int count;
    int* items;
};
class Timer : public TimerBase {
  public:
    char pad04[0x0c];
    unsigned char mFlag;
    char pad11[3];
    int mState;
    char pad18[8];
    List* volatile mList;
    void vfunc_9();
};
void Timer::vfunc_9() {
    if (!mFlag) {
        mState = 0;
        mFlag = 1;
        List* p = mList;
        unsigned int n = p->count;
        unsigned int i = 0;
        if (n > 0) {
            int* items = p->items;
            int* cur = items;
            do {
                if (*cur == 0) {
                    items[i] = (int)this;
                    return;
                }
                ++i;
                ++cur;
            } while (i < mList->count);
        }
    }
}
