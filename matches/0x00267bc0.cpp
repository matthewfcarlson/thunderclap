typedef unsigned int uint32;
struct Callback {
    virtual void vfunc_0(uint32 elapsed, uint32 data);
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
    char pad04[4];
    uint32 state;
    uint32 interval;
    char pad10[4];
    uint32 elapsed;
    Callback* callback;
    uint32 data;
};
namespace core {
struct TimerList {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(uint32 now);
    virtual void vfunc_5();
    char pad04[12];
    unsigned char started;
    char pad11[3];
    uint32 last;
    char pad18[4];
    uint32 count;
    Timer** timers;
};
void TimerList::vfunc_4(uint32 now) {
    if (!started) {
        last = now;
        started = 1;
        return;
    }
    uint32 delta = now - last;
    last = now;
    for (uint32 i = 0; i < count; ++i) {
        Timer* timer = timers[i];
        if (timer) {
            timer->elapsed += delta;
            if (timer->elapsed >= timer->interval) {
                if (timer->state == 1)
                    timer->vfunc_10();
                Callback* callback = timer->callback;
                uint32 amount = timer->elapsed;
                timer->elapsed = 0;
                if (callback) {
                    callback->vfunc_0(amount, timer->data);
                }
            }
        }
    }
}
} // namespace core