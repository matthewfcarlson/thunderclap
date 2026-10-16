// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 19/20, incomplete)
// FUN_000f7d60 @ 0x000f7d60
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

class Callback_f7d60 {
  public:
    virtual void v0(void* p);
};
class Metrics_f7d60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual float v8();
    virtual float v9(unsigned short* text);
    virtual void v10();
    virtual void v11();
    virtual float v12();
};
class Layer_f7d60 {
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
    virtual void v13();
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
struct Canvas {
    Layer_f7d60* layer;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float x, float y, float z);
};
void FUN_000fb690(unsigned short* dst, const unsigned short* src, int max);

class TextBox_f7d60 {
  public:
    char pad[0x24];
    Metrics_f7d60* sub[2];
    void FUN_000f7330(unsigned short* text, int index, float scale, int align, Callback_f7d60* cb);
    void FUN_000f7d60(const unsigned short* text, int index, float scale, int align, int mode, Callback_f7d60* cb);
};

void TextBox_f7d60::FUN_000f7d60(const unsigned short* text, int index, float scale, int align, int mode, Callback_f7d60* cb) {
    if (text == 0 || *text == 0)
        return;
    FUN_000fb690(((unsigned short*)&DAT_004de9b0), text, 0x1000);
    (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
    volatile float scaled = 14.0f * scale;
    volatile float ratio = scaled / sub[0]->v7();
    volatile float diff = ratio - 1.0f;
    float mag = diff;
    if (mag < 0.0f)
        mag = -mag;
    if (!(mag <= 1e-05f))
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(ratio, ratio, 1.0f);
    Metrics_f7d60* m = sub[index];
    volatile float top = m->v7();
    volatile float f = top - m->v8();
    if (mode == 1) {
        f = f - sub[index]->v7();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, f, 0.0f);
    } else if (mode == 2) {
        Metrics_f7d60* o = sub[index];
        volatile float t = o->v9(((unsigned short*)&DAT_004de9b0)) * 0.5f + f;
        f = t - o->v7();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, f, 0.0f);
    } else if (mode == 3) {
        Metrics_f7d60* o = sub[index];
        volatile float t = o->v9(((unsigned short*)&DAT_004de9b0)) + f;
        f = t - o->v7();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, f, 0.0f);
    }
    unsigned short* line = ((unsigned short*)&DAT_004de9b0);
    for (;;) {
        bool last = false;
        unsigned short* p = line;
        if (*p == 0) {
            last = true;
        } else {
            for (;;) {
                if (*p == 10) {
                    *p = 0;
                    break;
                }
                p++;
                if (*p == 0) {
                    last = true;
                    break;
                }
            }
        }
        (*(Canvas**)&DAT_0052c2ac)->layer->v15(0);
        FUN_000f7330(line, index, scale, align, cb);
        (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
        if (last)
            break;
        line = p + 1;
        Metrics_f7d60* o = sub[index];
        volatile float t = -o->v7();
        float y = t - o->v12();
        (*(Canvas**)&DAT_0052c2ac)->FUN_00293d40(0.0f, y, 0.0f);
    }
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
}
