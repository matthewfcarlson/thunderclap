typedef unsigned int uint32_267bc0;
struct Callback_267bc0 {
    virtual void vfunc_0(uint32_267bc0 elapsed, uint32_267bc0 data);
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
    uint32_267bc0 state;
    uint32_267bc0 interval;
    char pad10[4];
    uint32_267bc0 elapsed;
    Callback_267bc0* callback;
    uint32_267bc0 data;
};
namespace core {
struct TimerList {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(uint32_267bc0 now);
    virtual void vfunc_5();
    char pad04[12];
    unsigned char started;
    char pad11[3];
    uint32_267bc0 last;
    char pad18[4];
    uint32_267bc0 count;
    Timer** timers;
};
void TimerList::vfunc_4(uint32_267bc0 now) {
    if (!started) {
        last = now;
        started = 1;
        return;
    }
    uint32_267bc0 delta = now - last;
    last = now;
    for (uint32_267bc0 i = 0; i < count; ++i) {
        Timer* timer = timers[i];
        if (timer) {
            timer->elapsed += delta;
            if (timer->elapsed >= timer->interval) {
                if (timer->state == 1)
                    timer->vfunc_10();
                Callback_267bc0* callback = timer->callback;
                uint32_267bc0 amount = timer->elapsed;
                timer->elapsed = 0;
                if (callback) {
                    callback->vfunc_0(amount, timer->data);
                }
            }
        }
    }
}
} // namespace core