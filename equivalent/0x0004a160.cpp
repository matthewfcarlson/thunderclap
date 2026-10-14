// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 23/24, incomplete)
// CGrappleCharacterTemplateCondition::vfunc_7 @ 0x0004a160
struct Fighter_4a160 {
    char pad[4];
};
Fighter_4a160 *__fastcall FUN_000592a0(void *owner);

struct Unit_4a160 {
    char pad00[0x11c];
    struct Ids_4a160 *ids;
};

struct Ids_4a160 {
    unsigned __int64 FUN_000443c0();
};

struct Stats_4a160 {
    char pad00[0x330];
    Unit_4a160 *a330;
    Unit_4a160 *a334;
    Unit_4a160 *a338;
};
Stats_4a160 *__fastcall FUN_00059a30(Fighter_4a160 *f);

class CGrappleCharacterTemplateCondition {
public:
    virtual void vfunc_0();
    char pad04[8];
    int mode;
    unsigned int idLo;
    unsigned int idHi;
    bool vfunc_7(void *owner);
};

bool CGrappleCharacterTemplateCondition::vfunc_7(void *owner)
{
    if (owner == 0)
        return false;
    Stats_4a160 *stats = FUN_00059a30(FUN_000592a0(owner));
    Unit_4a160 *unit = stats->a334;
    if (unit == 0) {
        unit = stats->a330;
        if (unit == 0) {
            unit = stats->a338;
            if (unit == 0)
                return false;
        }
    }
    unsigned int lo = 0;
    unsigned int hi = 0;
    if (unit->ids != 0) {
        unsigned __int64 id = unit->ids->FUN_000443c0();
        lo = (unsigned int)id;
        hi = (unsigned int)(id >> 32);
    }
    if (mode == 0)
        return lo == idLo && hi == idHi;
    if (mode == 1)
        return !(lo == idLo && hi == idHi);
    return false;
}
