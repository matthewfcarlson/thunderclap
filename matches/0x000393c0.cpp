struct Target_393c0;
struct Mgr_393c0 {
    char pad[0x20];
    int sub;
};
struct Obj_393c0 {
    char pad[0x20];
};
struct Link_393c0 {
    virtual void V0();
    virtual void Release();
    int pad;
    Target_393c0* mTarget;
    int mKind;
};
struct Target_393c0 {
    char pad0[0x328];
    Link_393c0* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
};
struct Holder_393c0 {
    char pad[0x20];
};
struct Reg_393c0 {
    char pad[0x20];
    Holder_393c0* h;
};

struct Sys_393c0 {
    bool Check(Target_393c0* t);
};
extern Sys_393c0* g_sys;
extern const float kZero_393c0;

struct Dummy_393c0 {};

struct Sub_393c0 {
    bool Check(void* t);
};
struct Global_393c0 {
    char pad[0x20];
    Sub_393c0* sub;
};
extern Global_393c0* gGlobal_393c0;

struct T2 {
    char pad0[0x328];
    Link_393c0* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
    void Fn();
};

struct Other_393c0 {
    char pad[0x1b0c];
    float val;
};
struct LinkB {
    virtual void V0();
    virtual void Release();
    int pad;
    Other_393c0* mTarget;
    int mKind;
};

struct Sub2_393c0 {
    bool Check(void* t);
};
struct Glob2 {
    char pad[0x20];
    Sub2_393c0* sub;
};
extern Glob2* g_glob;

struct CCharacter_393c0 {
    char pad0[0x328];
    LinkB* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
    void Fn();
};

void CCharacter_393c0::Fn() {
    if (mFlag)
        return;
    g_glob->sub->Check(this);
    LinkB* l = mLink;
    if (l && l->mKind == 1) {
        Other_393c0* o = l->mTarget;
        if (o) {
            Sub2_393c0* s = g_glob->sub;
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
