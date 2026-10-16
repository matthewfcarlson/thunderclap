#include "gen/hulkfight.h"

struct Obj_12ba80 {
    void call(int);
    void tail();
};
struct Inner_12ba80 {
    char pad[8];
    Obj_12ba80* p;
};
struct Global_12ba80 {
    char pad[0x20];
    Inner_12ba80* inner;
};
extern Global_12ba80* g_12ba80;
extern Obj_12ba80* __cdecl FUN_000678d0();

void hulkfight::ai::ThreatBallAction::vfunc_4() {
    g_12ba80->inner->p->call(this->f_24);
    this->f_24 = 0;
    FUN_000678d0()->tail();
}
