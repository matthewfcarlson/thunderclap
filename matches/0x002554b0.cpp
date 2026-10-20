#include "gen/audio.h"

class SeqAction_2554b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void*);
    int pad4;
    char* mOwner;
    int mState;
    int mHandle;
};
extern int __cdecl Find(int, int);
extern void __cdecl Stop(int);
extern void __cdecl Start(int, int, int, bool, int);
struct Obj_2554b0 {
    char pad[0x3c];
    int value;
};

void audio::SeqActionCrossFade::vfunc_6(int __p0) { void * p = (void *)__p0;

    switch (this->f_0c) {
    case 1: {
        int value = ((Obj_2554b0*)p)->value;
        int h = Find(value, this->f_10);
        if (h) {
            if (h > 1 && h <= 4)
                this->f_0c = 2;
        } else {
            bool flag = ((*(char * *)&this->f_08)[0x18] == 0);
            int value2 = ((Obj_2554b0*)p)->value;
            Start(value2, this->f_10, 0, flag, 1);
        }
        break;
    }
    case 3: {
        int value = ((Obj_2554b0*)p)->value;
        int h = Find(value, this->f_10);
        if (!h) {
            this->f_0c = h;
            Stop(this->f_10);
            this->f_10 = 0;
        }
        break;
    }
    }
}
