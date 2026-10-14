// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 43/46, incomplete)
// FUN_000665e0 @ 0x000665e0
struct V3_665e0 {
    float x, y, z;
    float FUN_0022d110();
};

class Gauge_665e0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual float Value();
};

struct Level1_665e0 {
    char pad[0x70];
    Gauge_665e0 *gauge;
};

struct Level2_665e0 {
    char pad[0x10];
    Level1_665e0 *next;
};

class Unit_665e0 {
public:
    char pad0[0xa0];
    Level2_665e0 *state;
    char pad4[0x114 - 0xa4];
    int blocked;
    char pad118[0x1a0 - 0x118];
    bool alive;
    char pad1a1[0x1ed - 0x1a1];
    bool immune;

    bool FUN_001d7300();
    V3_665e0 *FUN_001d6b40();
};

struct Roster_665e0 {
    Unit_665e0 *FUN_001dee40(int lo, int hi);
};

struct Game_665e0 {
    char pad0[0xc];
    Roster_665e0 *roster;
};

struct Pair_665e0 {
    int lo;
    int hi;
};

struct Source_665e0 {
    char pad0[0x10];
    struct Ref_665e0 *ref;
};

struct Ref_665e0 {
    void FUN_00059a50(V3_665e0 *out);
};

extern Game_665e0 *DAT_004dd700;

class Squad {
public:
    char pad0[0x390];
    int count;
    char pad394[4];
    Pair_665e0 pairs[1];

    void FUN_00066530();
    bool FUN_000665e0(Pair_665e0 *out, Source_665e0 *from);
};

bool Squad::FUN_000665e0(Pair_665e0 *out, Source_665e0 *from)
{
    bool found = false;
    bool cleanup = false;
    int i = 0;
    if (from == 0) {
        if (count <= 0)
            return found;
        Pair_665e0 *p = pairs;
        do {
            if (found)
                break;
            Unit_665e0 *u = DAT_004dd700->roster->FUN_001dee40(p->lo, p->hi);
            if (u != 0 && u->alive && u->FUN_001d7300() && u->state->next->gauge->Value() != 0.0f &&
                !u->immune && u->alive && u->blocked == 0) {
                out->lo = p->lo;
                out->hi = p->hi;
                found = true;
            } else {
                cleanup = true;
            }
            i++;
            p++;
        } while (i < count);
    } else {
        int best = -1;
        float bestDist = -1.0f;
        V3_665e0 pos;
        from->ref->FUN_00059a50(&pos);
        if (count > 0) {
            Pair_665e0 *p = pairs;
            do {
                V3_665e0 d;
                d.z = 0;
                d.y = 0;
                d.x = 0;
                Unit_665e0 *u = DAT_004dd700->roster->FUN_001dee40(p->lo, p->hi);
                if (u != 0 && u->alive && u->FUN_001d7300() && u->state->next->gauge->Value() != 0.0f &&
                    !u->immune && u->alive && u->blocked == 0) {
                    V3_665e0 *at = u->FUN_001d6b40();
                    d.x = at->x;
                    d.y = at->y;
                    d.x = d.x - pos.x;
                    found = true;
                    d.y = d.y - pos.y;
                    d.z = at->z - pos.z;
                    float len = d.FUN_0022d110();
                    if (bestDist < 0.0f || len < bestDist) {
                        bestDist = len;
                        best = i;
                    }
                } else {
                    cleanup = true;
                }
                i++;
                p++;
            } while (i < count);
        }
        out->lo = pairs[best].lo;
        out->hi = pairs[best].hi;
    }
    if (cleanup)
        FUN_00066530();
    return found;
}
