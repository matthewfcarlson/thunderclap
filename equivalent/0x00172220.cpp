// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::TargetIconDistanceAction::vfunc_5 @ 0x00172220
struct Player_172220 {
    char pad[0x1e58];
    float scale;
};
struct Hero_172220 {
    char pad[0x124];
    Player_172220* player;
    char pad128[0x33c - 0x128];
    float value;
    void FUN_00025240(int v);
};
struct World {
    char pad[0x20];
    Hero_172220* hero;
};
struct Game_172220 {
    Player_172220* FUN_00059a30();
};
struct Holder_172220 {
    Game_172220* FUN_000592a0();
};
struct Range_172220 {
    char pad[0x14];
    float a;
    float b;
    int code;
};
extern World* DAT_004dd700;
class Action {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    char pad04[0x18];
    Range_172220* range;
    Holder_172220* holder;
    char FUN_00172220(int arg, int unused);
};
char Action::FUN_00172220(int arg, int unused) {
    if (arg != 0)
        return 1;
    Game_172220* g = holder->FUN_000592a0();
    if (g == 0)
        return 0;
    Player_172220* p = g->FUN_00059a30();
    if (p == 0)
        return 0;
    Hero_172220* h = DAT_004dd700->hero;
    if (p != h->player)
        return 0;
    h->value = (range->b - range->a) * p->scale + range->a;
    h->FUN_00025240(range->code);
    return 1;
}
