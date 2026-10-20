typedef unsigned int size_t;
inline void* operator new(size_t, void* p) {
    return p;
}
extern char DAT_004e6700;
void* __cdecl FUN_00247530(void*);
struct Action {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    void* unknown;
    void* event;
    int zero;
    Action(void* e) : event(e), zero(0) {}
};
struct Channel {
    void FUN_0025dc20(Action*);
};
namespace audio {
struct SeqEventChannelSendVolumes {
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
void SeqEventChannelSendVolumes::vfunc_2(int arg) {
    void* memory = FUN_00247530(&DAT_004e6700);
    Action* action = memory ? new (memory) Action(this) : 0;
    ((Channel*)arg)->FUN_0025dc20(action);
}
} // namespace audio