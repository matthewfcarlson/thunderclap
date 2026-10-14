// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PropAddToMissileCountAction::vfunc_5 @ 0x00181f90
struct Slot {
    int FUN_001d6c50();
    void FUN_001d6c60(int v);
};
struct Player {
    char pad[0x128];
    Slot* slot128;
    Slot* FUN_00035ef0(int i);
};
struct Game {
    Player* FUN_00059a30();
};
struct Holder {
    Game* FUN_000592a0();
};
struct Params {
    char pad[0x10];
    int index;
    int bonus;
};
class Action {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    char pad04[0x18];
    Params* params;
    Holder* holder;
    char FUN_00181f90(int arg, int unused);
};
char Action::FUN_00181f90(int arg, int unused) {
    if (arg == 0 && holder != 0) {
        Game* g = holder->FUN_000592a0();
        Player* p = g->FUN_00059a30();
        int index = params->index;
        if (p != 0) {
            Slot* s;
            if (index < 0) {
                s = p->slot128;
            } else if (index < 8) {
                s = p->FUN_00035ef0(index);
            } else {
                return 0;
            }
            if (s != 0) {
                int cur = s->FUN_001d6c50();
                s->FUN_001d6c60(params->bonus + cur);
            }
        }
    }
    return 0;
}
