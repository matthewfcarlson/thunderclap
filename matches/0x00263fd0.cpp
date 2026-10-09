extern "C" void* memcpy(void*, const void*, unsigned);
struct Job {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsDone();
};
struct Pump {
    void Tick();
};
extern Pump* g_pump;
Job* StartJob(void* dst, int mode, void* src, int one, unsigned n);
void __stdcall F(void* dst, void* src, unsigned n, int mode) {
    if (mode == 1) {
        memcpy(dst, src, n);
        return;
    }
    Job* j = StartJob(dst, mode, src, 1, n);
    j->v0();
    while (!j->IsDone())
        g_pump->Tick();
    j->v1();
}
