// STATUS: equivalent (tools/equiv.py level 3: 19995 inputs, branch coverage 42/42)
// FUN_000f7330 @ 0x000f7330
#include "decls/data/engine/pure3d/prop.h"
#include "gen/pure3d.h"
#include "compat/ptr.h"

struct Font_f7330 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual float v8();
    virtual void v9();
    virtual float v10(const unsigned short *text);
    virtual void v11(const unsigned short *text, int flags);
    virtual void v12();
    virtual void v13();
    virtual void v14(unsigned int *color);
};

struct ShaderFloatBroadcast_nv_f7330 {
    pure3d::ShaderFloatBroadcast *FUN_0028ee60(int tag, float f);
};

struct Token_f7330 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(pure3d::ShaderFloatBroadcast *f);
    virtual void v14();
    char pad04[0x14 - 4];
    float f14;
    float f18;
    char pad1c[4];
    float f20;
    float f24;
};

struct TokenTable {
    const char **FUN_000d3ee0();
    Token_f7330 *FUN_000d3f10(const char *name);
};

struct Mgr_f7330 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Holder_f7330 {
    Mgr_f7330 *mgr;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float a, float b, float c);
};

struct DrawableText_f7330 {
    char pad[0x18];
    void FUN_000ded90(const unsigned short *text, Font_f7330 *font);
};

struct Callback_f7330 {
    virtual void v0(DrawableText_f7330 *p);
};

struct Run_f7330 {
    const unsigned short *text;     // 0x00
    float width;                    // 0x04
    Token_f7330 *tok;                     // 0x08
    float tokW;                     // 0x0c
    float scale;                    // 0x10
    float tokY;                     // 0x14
};

extern void *FUN_0008d690(unsigned int size);
// finds the candidate name (ebx) inside the text (eax), returns the match
// equiv-conv: FUN_000f72e0 eax ebx
unsigned short *FUN_000f72e0(const unsigned short *text, const char *name);

class GlyphRun;

struct Frame_f7330 {
    union {
        const char **list;
        float acc;
    } u10;
    union {
        int best;
        int alpha;
        float fade;
    } u14;
    union {
        GlyphRun *self;
        float scale;
    } u18;
    union {
        const unsigned short *text;
        unsigned int color;
    } u1c;
    float h1;               // 0x20
    float lineH;            // 0x24
    union {
        DrawableText_f7330 probe;        // 0x28
        struct {
            char pad[0xc];
            float tokEnd;         // 0x34: the token's end, copied here while the probe is not yet live
        } scratch;
    } u28;
    Run_f7330 runs[16];           // 0x40
};

class GlyphRun {
public:
    char pad0[0x24];
    Font_f7330 *fonts[1];         // 0x24
    char pad28[0x114 - 0x28];
    TokenTable *table;      // 0x114
    float f118;
    void FUN_000f7330(unsigned short *text, int font, int unused, int mode, Callback_f7330 *cb);
};

void GlyphRun::FUN_000f7330(unsigned short *text, int font, int unused, int mode, Callback_f7330 *cb)
{
    Frame_f7330 f;
    f.u18.self = this;
    f.h1 = fonts[font]->v7();
    f.lineH = f.h1 - fonts[font]->v8();
    f.u1c.text = text;
    f.runs[0].text = text;
    f.runs[0].tok = 0;
    f.runs[1].text = 0;
    if (table != 0) {
        f.u10.list = table->FUN_000d3ee0();
        Run_f7330 *r = &f.runs[0];
        do {
            r->text = f.u1c.text;
            int i = 0;
            unsigned short *found = 0;
            f.u14.best = 0;
            r->tok = 0;
            r[1].text = 0;
            r[1].tok = 0;
            if (*f.u10.list == 0)
                break;
            const char *cand = *f.u10.list;
            do {
                unsigned short *res = FUN_000f72e0(f.u1c.text, cand);
                if (res != 0 && (found == 0 || res < found)) {
                    found = res;
                    f.u14.best = i;
                }
                cand = f.u10.list[i + 1];
                i++;
            } while (cand != 0);
            if (found == 0)
                break;
            *found = 0;
            const char *name = f.u10.list[f.u14.best];
            const char *e = name;
            while (*e++ != 0) {
            }
            int len = (int)(e - name - 1);
            f.u1c.text = found + len;
            r->tok = table->FUN_000d3f10(name);
            Token_f7330 *tok = r->tok;
            if (tok != 0) {
                hulk_freg a = tok->f14;
                hulk_freg b = tok->f18;
                f.u28.scratch.tokEnd = tok->f20;
                hulk_freg d = tok->f24 - b;
                if (d == 0.0f)
                    r->scale = 1.0f;
                else
                    r->scale = f118 / d * f.h1;
                r->tokY = b;
                r->tokW = (f.u28.scratch.tokEnd - a) * r->scale;
            }
            r++;
        } while (*f.u1c.text != 0);
    }

    f.u10.acc = 0;
    if (f.runs[0].text != 0) {
        Run_f7330 *r = &f.runs[0];
        do {
            r->width = fonts[font]->v10(r->text);
            f.u10.acc = r->width + f.u10.acc;
            if (r->tok != 0)
                f.u10.acc = f.u10.acc + r->tokW;
            r++;
        } while (r->text != 0);
    }
    if (mode != 0) {
        hulk_freg k;
        if (mode == 1)
            k = -0.5f;
        else
            k = -1.0f;
        (*(Holder_f7330**)&DAT_0052c2ac)->FUN_00293d40(f.u10.acc * k, 0, 0);
    }
    if (f.runs[0].text != 0) {
        Run_f7330 *r = &f.runs[0];
        do {
            if (cb != 0) {
                f.u28.probe.FUN_000ded90(r->text, fonts[font]);
                cb->v0(&f.u28.probe);
            }
            fonts[font]->v11(r->text, 0);
            (*(Holder_f7330**)&DAT_0052c2ac)->FUN_00293d40(r->width, 0, 0);
            Token_f7330 *tok = r->tok;
            if (tok != 0) {
                (*(Holder_f7330**)&DAT_0052c2ac)->mgr->v15(0);
                hulk_freg y = (-f.lineH - r->tokY * r->scale) - (f118 - 1.0f) * f.h1 * 0.5f;
                (*(Holder_f7330**)&DAT_0052c2ac)->FUN_00293d40(r->tokW * 0.5f, y, 0);
                (*(Holder_f7330**)&DAT_0052c2ac)->FUN_00293da0(r->scale, r->scale, r->scale);
                fonts[font]->v14(&f.u1c.color);
                f.u14.alpha = f.u1c.color >> 24;
                f.u14.fade = 1.0f - (float)f.u14.alpha * 0.003921569f;
                void *mem = FUN_0008d690(0x10);
                pure3d::ShaderFloatBroadcast *fd = 0;
                if (mem != 0)
                    fd = ((ShaderFloatBroadcast_nv_f7330*)(((pure3d::ShaderFloatBroadcast*)(((pure3d::ShaderFloatBroadcast *)mem)))))->FUN_0028ee60(0x45444146, f.u14.fade);
                tok->v13(fd);
                tok->v8(0, 0);
                tok->v14();
                (*(Holder_f7330**)&DAT_0052c2ac)->mgr->v16(0);
                (*(Holder_f7330**)&DAT_0052c2ac)->FUN_00293d40(r->tokW, 0, 0);
            }
            r++;
        } while (r->text != 0);
    }
}
