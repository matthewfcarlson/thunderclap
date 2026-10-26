#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* p) {
    return p;
}
void* __cdecl FUN_00247530(void*);
struct SeqActionChannelSendVolumes_24f230 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    void* unknown;
    void* event;
    int zero;
    SeqActionChannelSendVolumes_24f230(void* e) : event(e), zero(0) {}
};
struct Channel {
    void FUN_0025dc20(SeqActionChannelSendVolumes_24f230*);
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
    void* memory = FUN_00247530(((char*)&DAT_004e6700));
    SeqActionChannelSendVolumes_24f230* action = memory ? new (memory) SeqActionChannelSendVolumes_24f230(this) : 0;
    ((Channel*)arg)->FUN_0025dc20(action);
}
} // namespace audio