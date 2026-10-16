#include "gen/audio.h"

extern "C" char DAT_0042a2b0[];
typedef unsigned char u8;
struct Sub_254520 {
    void Setup(const char* s);
    char pad[8];
    u8 flags;
    char p2[3];
    unsigned int bits;
    unsigned int zero;
};
class Stream_254520 {
  public:
    int vf;
    void BaseInit();
    char pad[4];
    Sub_254520 sub;
};
extern void* Alloc(void*);
extern int gPool_254520;

void* audio::SeqEventStreamType::vfunc_3() {
    Stream_254520* p = (Stream_254520*)Alloc(&gPool_254520);
    if (p) {
        p->BaseInit();
        Sub_254520* s = &p->sub;
        p->vf = ((int)DAT_0042a2b0);
        s->Setup("MyRsdFile");
        s->flags &= 0xfe;
        s->bits &= 0x80000000;
        s->zero = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
