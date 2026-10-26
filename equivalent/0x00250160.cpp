// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 9/9)
// audio::SeqActionWait::vfunc_6 @ 0x00250160
#include "compat/ptr.h"
#include "gen/audio.h"

struct Str_250160 {
    char *data;
    short mode;
    short pad6;
    short len;
    short pad10;
    Str_250160 *FUN_0023fac0();
    Str_250160 *FUN_0023fc40(const char *text, int len);
    bool FUN_00240310(const Str_250160 *other);
};
extern "C" void __fastcall FUN_00240060(Str_250160 *s);

struct Table_250160 { char pad[0x10]; };
struct Mgr_250160 {
    char pad[0x5c];
    Table_250160 table;
};
struct Ctx_250160 {
    char pad[0x3c];
    Mgr_250160 *mgr;
};
struct WaitData {
    char pad[8];
    Str_250160 name;
};

void FUN_002613b0(Table_250160 *t, Str_250160 *out, Str_250160 *in);

class SeqAction_250160 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Ctx_250160 *ctx);
    char pad04[4];
    WaitData *data;     // 0x08
    int state;          // 0x0c
};

namespace audio {
}
void audio::SeqActionWait::vfunc_6(hulk_intptr __p0) { Ctx_250160 * ctx = (Ctx_250160 *)__p0;

    Str_250160 value;
    Str_250160 probe;
    switch (this->f_0c) {
    case 1:
    case 4:
        this->f_0c = 2;
        break;
    case 3: {
        value.FUN_0023fac0();
        FUN_002613b0(&ctx->mgr->table, &value, &(*(WaitData * *)&this->f_08)->name);
        bool same = probe.FUN_0023fc40("t", 2)->FUN_00240310(&value);
        FUN_00240060(&probe);
        if (same)
            this->f_0c = 0;
        FUN_00240060(&value);
        break;
    }
    case 5:
        this->f_0c = 0;
        break;
    }
}
