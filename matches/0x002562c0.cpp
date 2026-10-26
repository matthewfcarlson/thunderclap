#include "gen/audio.h"
#include "decls/data/engine/audio.h"
// data: pool_2562c0 = DAT_004e75b8

extern "C" void* __cdecl alloc(void*);
class Part {
  public:
    char pad[8];
    unsigned char flags;
    char pad2[3];
    unsigned int bits;
    int extra;
    void init(const char*);
    Part(unsigned char* flag) {
        *flag = 0;
        init("MyRsdFile");
        flags &= 0xfe;
        bits &= 0x80000000;
        extra = 0;
    }
};
class Base_2562c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[4];
    Base_2562c0();
};
class Clip_2562c0 : public Base_2562c0 {
  public:
    unsigned char flag;
    char pad[7];
    Part part;
    Clip_2562c0() : Base_2562c0(), part(&flag) {}
};

void* audio::SeqEventClipType::vfunc_3() {
    void* p = alloc(((char*)&DAT_004e75b8));
    if (p) {
        Clip_2562c0* q = (Clip_2562c0*)p;
        q->Clip_2562c0::Clip_2562c0();
        return (void*)(q);
    }
    return (void*)(0);
}
