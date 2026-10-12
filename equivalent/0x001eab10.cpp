// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_001eab10 @ 0x001eab10
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;
extern "C" int sprintf(char *buf, const char *fmt, ...);

namespace core {
struct IRefCount {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}

struct Pair {
    int a, b;
};

namespace audio {
class Sequence : public core::IRefCount {
public:
    Pair *FUN_00243390();
};
class Mix : public core::IRefCount {
public:
    Pair *FUN_00243390();
};
class Mixer : public core::IRefCount {
};
class ListenerEffectXBox : public core::IRefCount {
public:
    Pair *FUN_00243390();
};
}

struct Handle {
    char FUN_00266750();
    struct Group *FUN_00266700();
    void FUN_00263e90();
};

struct Cursor {
    unsigned int a;
    int b;
    struct Group *c;
    void FUN_002314a0(unsigned int v);
    core::IRefCount *FUN_00231640();
    core::IRefCount *FUN_002314c0();
};

struct Group {
    char pad0[0xc];
    unsigned int f0c;
    void FUN_00266090();
};

struct Loader {
    void FUN_00265920(const char *path, Handle **out, int flag);
    int FUN_00264870();
    void FUN_00264860(int v);
};

struct Flags {
    bool FUN_00092de0(int id);
};

struct Opt {
    Flags *FUN_00086340();
};

struct Item {
    void FUN_000bd1b0(int v);
};

struct Scene {
    Item *FUN_00086280();
};

struct Game {
    char pad0[0x54];
    Scene *scene;           // 0x54
};

struct Track {
    char pad0[0x10];
    int f10;
    int f14;
    void FUN_001ea6b0(audio::Sequence *s, int v);
    void FUN_001e9bf0();
};

struct Voice {
    char pad0[8];
    audio::Mix *mix;        // 0x8
    int fc;                 // 0xc
};

struct Sink {
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3();
    virtual void k4(int a, int b, core::IRefCount *e);
};

extern Loader *DAT_00527c58;
extern Game *DAT_004dd700;
extern Opt *DAT_004dd6ec;
extern void FUN_00087990();
extern void *FUN_00240750();
extern int __cdecl FUN_00242c30(void *mgr, int v);
extern bool __cdecl FUN_001e9bc0(Pair p);

class Player {
public:
    char pad0[0x518];
    Sink *sink;             // 0x518
    int FUN_001e98b0(Pair *p);
    Track *FUN_001e97f0();
    Voice *FUN_001e8960();
    void FUN_001eab10(const char *name);
};

void Player::FUN_001eab10(const char *name)
{
    unsigned int cookie = DAT_004d9968;
    char buf[0x80];
    Handle *h = 0;
    for (int i = 0; i < 0x80; i++)
        buf[i] = 0;
    sprintf(buf, "sound\\%s", name);
    DAT_00527c58->FUN_00265920(buf, &h, 1);
    int saved = DAT_00527c58->FUN_00264870();
    DAT_00527c58->FUN_00264860(250000);
    while (!h->FUN_00266750()) {
        FUN_00087990();
        DAT_004dd700->scene->FUN_00086280()->FUN_000bd1b0(0);
    }
    DAT_00527c58->FUN_00264860(saved);
    if (h->FUN_00266700() != 0) {
        h->FUN_00266700()->FUN_00266090();
        Group *g = h->FUN_00266700();
        Cursor it;
        it.FUN_002314a0(g->f0c);
        it.c = g;
        core::IRefCount *e = it.FUN_00231640();
        while (e != 0) {
            audio::Sequence *seq = 0;
            audio::Mix *mix = 0;
            audio::ListenerEffectXBox *fx = 0;
            if (dynamic_cast<audio::Sequence *>(e)) {
                seq = dynamic_cast<audio::Sequence *>(e);
                Pair *pr = seq->FUN_00243390();
                Pair p;
                int ca = pr->a;
                p.a = ca;
                p.b = pr->b;
                if (FUN_001e98b0(&p) == 0) {
                    bool skip = false;
                    if (!DAT_004dd6ec->FUN_00086340()->FUN_00092de0(2)) {
                        Pair arg;
                        arg.a = ca;
                        arg.b = p.b;
                        if (FUN_001e9bc0(arg))
                            skip = true;
                    }
                    if (!skip) {
                        Track *t = FUN_001e97f0();
                        t->f14 = p.b;
                        t->f10 = p.a;
                        t->FUN_001ea6b0(seq, 0);
                        t->FUN_001e9bf0();
                        Pair *q = seq->FUN_00243390();
                        sink->k4(q->a, q->b, e);
                    }
                }
            } else if (dynamic_cast<audio::Mix *>(e)) {
                mix = dynamic_cast<audio::Mix *>(e);
                Voice *v = FUN_001e8960();
                v->mix = mix;
                void *mgr = FUN_00240750();
                v->fc = FUN_00242c30(mgr, (int)v->mix);
                Pair *q = mix->FUN_00243390();
                sink->k4(q->a, q->b, e);
            } else if (dynamic_cast<audio::Mixer *>(e)) {
                dynamic_cast<audio::Mixer *>(e);
            } else if (dynamic_cast<audio::ListenerEffectXBox *>(e)) {
                fx = dynamic_cast<audio::ListenerEffectXBox *>(e);
                Pair *q = fx->FUN_00243390();
                sink->k4(q->a, q->b, e);
            }
            e = it.FUN_002314c0();
        }
        h->FUN_00263e90();
    }
    __security_check_cookie(cookie);
}
