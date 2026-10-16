#include "gen/audio.h"

typedef unsigned int size_t;
namespace audio {
class SeqEvent_251590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[4];
    int x;
    int y;
    char flag;
    char pad2[3];
    class Field {
      public:
        void init(const char*, int);
    } field;
    SeqEvent_251590();
};
class SeqEventPlayTrack_251590 : public SeqEvent_251590 {
  public:
    SeqEventPlayTrack_251590();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
} // namespace audio
extern char heap;
extern void* alloc(char*);
inline void* operator new(size_t n, char* h) {
    return alloc(h);
}
audio::SeqEventPlayTrack_251590::SeqEventPlayTrack_251590() {
    x = 0;
    y = 0;
    flag = 0;
    field.init("MySeqTrack", 2);
}
void* audio::SeqEventPlayTrackType::vfunc_3() {
    return (void*)(new (&heap) audio::SeqEventPlayTrack_251590);
}
