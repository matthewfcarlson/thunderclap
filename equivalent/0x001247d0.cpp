// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 27/28, incomplete)
// hulkfight::ai::CanSeeTargetCondition::vfunc_6 @ 0x001247d0
struct V3 { float x, y, z; };

class fight_Params {
public:
    virtual void vfunc_0();
};

class CFightParams : public fight_Params {
public:
    virtual void vfunc_0();
};

struct Part {
    char FUN_000fc800();
};

struct Unit {
    char pad[0x58];
    Part part;
};

struct Locator {
    char FUN_00036ac0(V3* out);
};

struct Body {
    char pad0[8];
    Locator* loc;
    int mode;
    char pad1[0x40 - 0x10];
    V3 pos;
};

struct Owner {
    char pad0[0x328];
    Body* body;
    char pad1[0x1b8c - 0x32c];
    float lastTime;
    char lastResult;
    char pad2[0x1ca0 - 0x1b91];
    Unit* unit;
    char FUN_00036ac0(V3* out);
};

struct Clock {
    float FUN_00066280();
};

struct Ctl {
    void FUN_001dcf60(int a);
};
struct Sys {
    char pad[0xc];
    Ctl* ctl;
};

class Context { public: char pad[4]; };

Context* __fastcall FUN_000592a0(void* obj);
Owner* __fastcall FUN_00059a30(Context* ctx);
Clock* FUN_000678d0();
extern Sys* DAT_004dd700;
bool __cdecl FUN_00203190(V3* a1, V3* a2, int a3, Body* a4, int a5, Owner* a6);

class CanSeeTargetCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight_Params* params, int c);
    char pad04[8];
    char expected;
    char flag;
};

char CanSeeTargetCondition::vfunc_6(int a, fight_Params* params, int c)
{
    if (dynamic_cast<CFightParams*>(params) == 0)
        return 0;
    Owner* owner = FUN_00059a30(FUN_000592a0(params));
    V3 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    owner->FUN_00036ac0(&pos);
    pos.y = pos.y + 1.0f;
    float now = FUN_000678d0()->FUN_00066280();
    Body* body = owner->body;
    float last = owner->lastTime;
    if (body == 0)
        return 0;
    V3 bpos = body->pos;
    char f = flag;
    if (f != 0 && body->mode == 1) {
        Unit* u = owner->unit;
        if (u != 0) {
            Part* p = &u->part;
            if (p != 0)
                return expected == p->FUN_000fc800();
        } else if (body->loc != 0) {
            body->loc->FUN_00036ac0(&bpos);
        }
    }
    if (last != 0.0f && last - 0.2f > now) {
        owner->lastTime = 0.0f;
        last = 0.0f;
    }
    if (last + 0.2f <= now) {
        bpos.y = bpos.y + 0.5f;
        DAT_004dd700->ctl->FUN_001dcf60(0);
        char r = FUN_00203190(&pos, &bpos, 0, body, f == 0, owner);
        DAT_004dd700->ctl->FUN_001dcf60(1);
        owner->lastResult = r;
        owner->lastTime = now;
        return expected == r;
    }
    return expected == owner->lastResult;
}
