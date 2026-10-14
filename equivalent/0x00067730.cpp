// STATUS: equivalent (tools/equiv.py level 3: 490 inputs, branch coverage 12/12)
// FUN_00067730 @ 0x00067730
// FUN_00067730: once the clock passes the next-update time, refresh every entry's score and schedule the next update
struct Clock {
    float FUN_00086080();
};

struct World {
    char pad00[0x2c];
    int f2c;
};

struct Pos {
    int x;
    int y;
};

struct Entry {
    char pad00[0x10];
    Pos pos;
    float score;
};

struct List {
    char data[0x58];
    Entry *FUN_00230ea0();
    Entry *FUN_00230800(Entry *e);
};

extern World *DAT_004dd700;

class Ticker {
public:
    int f0;
    Clock *clock;
    char pad08[0x2ec];
    List list;
    float nextTime;
    char pad350[0x378 - 0x350];
    float interval;
    char pad37c[0x388 - 0x37c];
    Pos last;

    float FUN_00067110(Pos *p);
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
    for (Entry *e = list.FUN_00230ea0(); e != 0; e = list.FUN_00230800(e)) {
        e->score = FUN_00067110(&e->pos) * 0.2f;
        last = e->pos;
    }
    nextTime = clock->FUN_00086080() + interval;
}
