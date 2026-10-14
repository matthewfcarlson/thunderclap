// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 29/29)
// audio::SeqActionClip::vfunc_6 @ 0x00256420
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace audio { class Clip; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

struct ClipRef_256420 {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
};

struct Clip {
    char pad0[0x22];
    unsigned short refs;
    char pad24[4];
    void *source;
};

class ClipLookup_256420 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Clip *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

struct Env_256420 {
    char pad0[0x14];
    float scale;
    char pad18[0x88 - 0x18];
    ClipLookup_256420 *clips;
    char pad8c[0xb4 - 0x8c];
    unsigned char flags;
};

struct Voice_256420 {
    char pad0[0x1c];
    float *volume;
    float gain;
    float pan;
    char pad28[0x44 - 0x28];
    unsigned int *params;
};

struct Ctx_256420 {
    char pad0[4];
    Voice_256420 *voice;
    char pad8[0x3c - 8];
    Env_256420 *env;
    char *ownerLink;
};

class SeqActionClip;

unsigned int *__cdecl FUN_0025d060(void *source);
void __cdecl FUN_0025c320(unsigned int *p, unsigned int *out, int bit0, int bit1);
int __cdecl FUN_00259610(unsigned int *params, int one, void *source);
void __cdecl FUN_00258ea0(int handle, int arg);
int __cdecl FUN_00259c50(int handle);
void __cdecl FUN_00259b40(int handle);
void __cdecl FUN_00258c80(int handle, float v);

union Flag_256420 {
    char b;
    int w;
};

struct Frame_256420 {
    char pad0[4];
    int saved;                  // 0x10
    Flag_256420 bit1;                  // 0x14
    Flag_256420 bit0;                  // 0x18
    int caster;                 // 0x1c, holds a DynamicCaster
    unsigned int buf[63];       // 0x20
};

class SeqActionClip {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6(Ctx_256420 *ctx);
    char pad04[4];
    ClipRef_256420 *ref;       // 0x08
    int f0c;
    Clip *clip;         // 0x10
    int handle;         // 0x14
    int state;          // 0x18
    void FUN_00256150(Ctx_256420 *ctx);
    void FUN_00255e60(Ctx_256420 *ctx);
    void FUN_00255ed0(Ctx_256420 *ctx);
};

int SeqActionClip::vfunc_6(Ctx_256420 *ctx)
{
    Frame_256420 fr;
    do {
        fr.saved = state;
        switch (state) {
        case 1: {
            char *link = ctx->ownerLink;
            SeqActionClip *owner = link ? (SeqActionClip *)(link - 4) : 0;
            if (owner == this) {
                content::LoadInventory::DynamicCaster<audio::Clip> *caster =
                    new (&fr.caster) content::LoadInventory::DynamicCaster<audio::Clip>();
                unsigned __int64 id = ((unsigned __int64)ref->idHi << 32) | ref->idLo;
                clip = ctx->env->clips->lookup(caster, id);
                if (clip) {
                    clip->refs++;
                    unsigned int *params = ctx->voice->params;
                    if (params == 0) {
                        unsigned char flags = ctx->env->flags;
                        fr.bit1.b = (flags >> 1) & 1;
                        fr.bit0.b = flags & 1;
                        params = fr.buf;
                        FUN_0025c320(FUN_0025d060(clip->source), params, fr.bit0.w, fr.bit1.w);
                    }
                    handle = FUN_00259610(params, 1, clip->source);
                    FUN_00258ea0(handle, f0c);
                }
                state = 2;
            }
            break;
        }
        case 3:
            if (handle != 0 && FUN_00259c50(handle) != 0) {
                FUN_00256150(ctx);
                Voice_256420 *v = ctx->voice;
                Env_256420 *e = ctx->env;
                FUN_00258c80(handle, *v->volume * e->scale * v->gain * v->pan);
                FUN_00255e60(ctx);
                FUN_00255ed0(ctx);
            } else {
                state = 5;
            }
            break;
        case 4:
            if (handle == 0 || FUN_00259c50(handle) == 0)
                state = 2;
            break;
        case 5:
            if (handle != 0) {
                if (FUN_00259c50(handle) != 0)
                    break;
                FUN_00259b40(handle);
                Clip *c = clip;
                handle = 0;
                c->refs--;
                clip = 0;
            }
            state = 0;
            break;
        }
    } while (fr.saved != state);
    return state;
}
