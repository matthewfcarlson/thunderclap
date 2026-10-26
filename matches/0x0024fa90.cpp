#include "gen/audio.h"
#include "decls/data/engine/audio.h"
// data: bss = DAT_004e6848

extern "C" void* __cdecl Alloc(void*);
extern "C" int __cdecl Lookup(const char*, int);
namespace audio {
class SeqEventType_24fa90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
    SeqEventType_24fa90();
};
class SeqEventChannelSends_24fa90 : public SeqEventType_24fa90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
    char pad[4];
    int data[64];
    int member;
    SeqEventChannelSends_24fa90() : SeqEventType_24fa90() {
        member = Lookup("this", 0);
        for (int i = 0; i < 64; ++i)
            data[i] = 0;
    }
};

} // namespace audio
void* audio::SeqEventChannelSendsType::vfunc_3() {
    SeqEventChannelSends_24fa90* p = (SeqEventChannelSends_24fa90*)Alloc(((int*)((char*)&DAT_004e6800 + 72)));
    if (p) {
        p->SeqEventChannelSends_24fa90::SeqEventChannelSends_24fa90();
        return (void*)(p);
    }
    return (void*)(0);
}
