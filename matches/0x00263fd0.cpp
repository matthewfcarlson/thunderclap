extern "C" void* memcpy(void*, const void*, unsigned);
struct Job_263fd0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsDone();
};
struct Pump_263fd0 {
    void Tick();
};
extern Pump_263fd0* g_pump;
Job_263fd0* StartJob(void* dst, int mode, void* src, int one, unsigned n);
void __stdcall F(void* dst, void* src, unsigned n, int mode) {
    if (mode == 1) {
        memcpy(dst, src, n);
        return;
    }
    Job_263fd0* j = StartJob(dst, mode, src, 1, n);
    j->v0();
    while (!j->IsDone())
        g_pump->Tick();
    j->v1();
}
