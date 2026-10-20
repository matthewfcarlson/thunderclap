// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 6/6)
// FUN_001c23c0 @ 0x001c23c0
#include "compat/ptr.h"
extern "C" char DAT_004216d4[];
void *FUN_0008d690(unsigned int size);

struct HulkShaderCallback {
    hulk_intptr vptr;
    int f04;
    int f08;
    float f0c;
    int f10;
    unsigned int color0;
    unsigned int color1;
};

class Canvas {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void SetCallback(HulkShaderCallback *cb);
    char pad04[12];
    HulkShaderCallback *callback;
};

HulkShaderCallback *__stdcall FUN_001c23c0(Canvas *canvas, bool create)
{
    if (canvas->callback == 0 && create) {
        HulkShaderCallback *cb = (HulkShaderCallback *)FUN_0008d690(0x1c);
        if (cb) {
            cb->f04 = 0;
            cb->vptr = (hulk_intptr)DAT_004216d4;
            cb->f08 = 0;
            cb->f0c = 1.0f;
            cb->f10 = 0;
            cb->color0 = 0xff000000;
            cb->color1 = 0xff000000;
        }
        canvas->SetCallback(cb);
        return cb;
    }
    return canvas->callback;
}
