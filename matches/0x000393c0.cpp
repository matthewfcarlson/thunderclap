struct Target;
struct Mgr {
    char pad[0x20];
    int sub;
};
struct Obj {
    char pad[0x20];
};
struct Link {
    virtual void V0();
    virtual void Release();
    int pad;
    Target* mTarget;
    int mKind;
};
struct Target {
    char pad0[0x328];
    Link* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
};
struct Holder {
    char pad[0x20];
};
struct Reg {
    char pad[0x20];
    Holder* h;
};

struct Sys {
    bool Check(Target* t);
};
extern Sys* g_sys;
extern const float kZero;

struct Dummy {};

struct Sub {
    bool Check(void* t);
};
struct Global {
    char pad[0x20];
    Sub* sub;
};
extern Global* gGlobal;

struct T2 {
    char pad0[0x328];
    Link* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
    void Fn();
};

struct Other {
    char pad[0x1b0c];
    float val;
};
struct LinkB {
    virtual void V0();
    virtual void Release();
    int pad;
    Other* mTarget;
    int mKind;
};

struct Sub2 {
    bool Check(void* t);
};
struct Glob2 {
    char pad[0x20];
    Sub2* sub;
};
extern Glob2* g_glob;

struct T3 {
    char pad0[0x328];
    LinkB* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
    void Fn();
};

void T3::Fn() {
    if (mFlag)
        return;
    g_glob->sub->Check(this);
    LinkB* l = mLink;
    if (l && l->mKind == 1) {
        Other* o = l->mTarget;
        if (o) {
            Sub2* s = g_glob->sub;
            if (s) {
                if (s->Check(o)) {
                    if (o->val > 0.0f)
                        return;
                }
            }
        }
    }
    if (mLink) {
        mLink->Release();
        mLink = 0;
    }
}
