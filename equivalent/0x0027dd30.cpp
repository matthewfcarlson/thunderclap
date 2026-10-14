// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 14/14)
// FUN_0027dd30 @ 0x0027dd30
unsigned __int64 __cdecl FUN_0027b020(const char *name);

extern unsigned int DAT_0052c290;
extern unsigned int DAT_0052c294;
extern unsigned int DAT_0052c298;

struct Effect {
    char pad0[0x40];
    unsigned int idLo;      // 0x40
    unsigned int idHi;      // 0x44
    char pad48[8];
    float time;             // 0x50
    char pad54[4];
};

struct EffectList {
    char pad0[0x44];
    int count;              // 0x44
    Effect *items;          // 0x48
};

class Player {
public:
    void FUN_0027cd10(Effect *e);
    void FUN_0027dd30(EffectList *list, float lo, float hi);
};

void Player::FUN_0027dd30(EffectList *list, float lo, float hi)
{
    if (!(DAT_0052c298 & 1)) {
        DAT_0052c298 |= 1;
        unsigned __int64 id = FUN_0027b020("Effect");
        DAT_0052c290 = (unsigned int)id;
        DAT_0052c294 = (unsigned int)(id >> 32);
    }
    for (int i = 0; i < list->count; i++) {
        Effect *e = &list->items[i];
        if (e->idLo == DAT_0052c290 && e->idHi == DAT_0052c294 && e->time >= lo && e->time < hi)
            FUN_0027cd10(e);
    }
}
