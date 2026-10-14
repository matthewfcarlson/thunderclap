// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// audio::SeqActionWait::vfunc_6 @ 0x00250160
struct Str {
    char *data;
    short mode;
    short pad6;
    short len;
    short pad10;
    Str *FUN_0023fac0();
    Str *FUN_0023fc40(const char *text, int len);
    bool FUN_00240310(const Str *other);
};
extern "C" void __fastcall FUN_00240060(Str *s);

struct Table { char pad[0x10]; };
struct Mgr {
    char pad[0x5c];
    Table table;
};
struct Ctx {
    char pad[0x3c];
    Mgr *mgr;
};
struct WaitData {
    char pad[8];
    Str name;
};

void FUN_002613b0(Table *t, Str *out, Str *in);

class SeqAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Ctx *ctx);
    char pad04[4];
    WaitData *data;     // 0x08
    int state;          // 0x0c
};

namespace audio {
class SeqActionWait : public SeqAction {
public:
    virtual void vfunc_6(Ctx *ctx);
};
}

void audio::SeqActionWait::vfunc_6(Ctx *ctx)
{
    Str value;
    Str probe;
    switch (state) {
    case 1:
    case 4:
        state = 2;
        break;
    case 3: {
        value.FUN_0023fac0();
        FUN_002613b0(&ctx->mgr->table, &value, &data->name);
        bool same = probe.FUN_0023fc40("t", 2)->FUN_00240310(&value);
        FUN_00240060(&probe);
        if (same)
            state = 0;
        FUN_00240060(&value);
        break;
    }
    case 5:
        state = 0;
        break;
    }
}
