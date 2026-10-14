// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// CDrainHealthAction::vfunc_7 @ 0x000152a0
// The float argument word: its low byte is reused as a flag local, the upper bytes stay stale.
union DtArg {
    float f;
    unsigned char flag;
    unsigned int word;
};

struct Link {
    char pad00[0x12c];
    int id;                  // 0x12c
};

struct Fighter {
    char pad00[0x12c];
    int id;                  // 0x12c
    char pad130[0x204];
    Link *link334;           // 0x334
    Link *link338;           // 0x338
    void FUN_00043350(float amount, int source, int zero0, float one, int zero1, unsigned int flagWord);
};

struct Attacker {
    char pad00[0x4c];
    int sourceId;            // 0x4c
    char pad50[0x41];
    unsigned char flag91;    // 0x91
};

struct Context {
    Fighter *FUN_00059a30();
};

class Combatant {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Attacker *GetAttacker();     // slot 3
    Context *FUN_000592a0();
};

class CDrainHealthAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual bool vfunc_7(DtArg dt);
    char pad04[0x18];
    Combatant *combatant;    // 0x1c
    float rate;              // 0x20
};

bool CDrainHealthAction::vfunc_7(DtArg dt) {
    float amount = dt.f * rate;
    Fighter *fighter = combatant->FUN_000592a0()->FUN_00059a30();
    int source = 0;
    dt.flag = 0;
    Link *link = fighter->link338;
    if (link == 0)
        link = fighter->link334;
    if (link != 0) {
        source = link->id;
    } else {
        Attacker *attacker = combatant->GetAttacker();
        if (attacker != 0) {
            source = attacker->sourceId;
            if (source == fighter->id)
                source = 0;
            dt.flag = attacker->flag91;
        }
    }
    fighter->FUN_00043350(amount, source, 0, 1.0f, 0, dt.word);
    return true;
}
