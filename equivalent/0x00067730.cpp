// STATUS: equivalent (tools/equiv.py level 3: 490 inputs, branch coverage 12/12)
// FUN_00067730 @ 0x00067730
// FUN_00067730: once the clock passes the next-update time, refresh every entry's score and schedule the next update
#include "decls/address.h"
struct Clock_67730 {
    float FUN_00086080();
};

struct World {
    char pad00[0x2c];
    int f2c;
};

struct Pos_67730 {
    int x;
    int y;
};

struct Entry_67730 {
    char pad00[0x10];
    Pos_67730 pos;
    float score;
};

struct List_67730 {
    char data[0x58];
    Entry_67730 *FUN_00230ea0();
    Entry_67730 *FUN_00230800(Entry_67730 *e);
};


class Ticker {
public:
    int f0;
    Clock_67730 *clock;
    char pad08[0x2ec];
    List_67730 list;
    float nextTime;
    char pad350[0x378 - 0x350];
    float interval;
    char pad37c[0x388 - 0x37c];
    Pos_67730 last;

    float FUN_00067110(Pos_67730 *p);
    void FUN_00067730();
};

void Ticker::FUN_00067730()
{
    if (clock == 0)
        return;
    if (f0 == 0) {
        f0 = DAT_004dd700->f2c;
        if (f0 == 0)
            return;
    }
    if (!(clock->FUN_00086080() >= nextTime))
        return;
    for (Entry_67730 *e = list.FUN_00230ea0(); e != 0; e = list.FUN_00230800(e)) {
        e->score = FUN_00067110(&e->pos) * 0.2f;
        last = e->pos;
    }
    nextTime = clock->FUN_00086080() + interval;
}
