namespace core {
class Timer;
struct TimerManager {
    char reserved[0x1c];
    unsigned int count;
    Timer** timers;
};
class Timer {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    char pad[0xc];
    unsigned char f_10;
    char pad2[0xf];
    TimerManager* volatile f_20;
};
void Timer::vfunc_10() {
    if (f_10) {
        TimerManager* mgr = f_20;
        f_10 = 0;
        unsigned int i = 0;
        if (mgr->count > 0) {
            Timer** list = mgr->timers;
            Timer** cur = list;
            do {
                if (*cur == this) {
                    list[i] = 0;
                    break;
                }
                ++i;
                ++cur;
            } while (i < f_20->count);
        }
    }
}
} // namespace core