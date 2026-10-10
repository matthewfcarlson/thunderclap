// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 8/8)
// core::Timer::vfunc_10 @ 0x00267cf0
namespace core {
struct Timer;
struct TimerManager {
    char reserved[0x1c];
    unsigned int count;
    Timer **timers;
};
struct Timer {
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
    char padding[0x0c];
    unsigned char active;
    char padding2[0x0f];
    TimerManager *manager;
};
void Timer::vfunc_10() {
    if (active) {
        active = 0;
        if (manager->count) {
            Timer **list = manager->timers;
            for (unsigned int i = 0; i < manager->count; ++i) {
                if (list[i] == this) {
                    list[i] = 0;
                    break;
                }
            }
        }
    }
}
}