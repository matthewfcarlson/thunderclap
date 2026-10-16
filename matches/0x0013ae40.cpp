#include "gen/hulkfight.h"

class AnimationTrack_13ae40 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
};

class NewObject {
  public:
    int Init(hulkfight::motion::GrappleAnimationTrack*, int);
};
extern int __cdecl Find(int);
extern NewObject* __cdecl Alloc(int);

int hulkfight::motion::GrappleAnimationTrack::vfunc_10(int a, int b, int c) {
    int v = Find(c);
    if (v) {
        NewObject* p = Alloc(0x28);
        if (p)
            return p->Init(this, v);
    }
    return 0;
}
