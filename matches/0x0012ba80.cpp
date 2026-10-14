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
class ThreatBallAction {
  public:
    char pad[0x24];
    int field;
    void vfunc_4();
};
void ThreatBallAction::vfunc_4() {
    g_12ba80->inner->p->call(field);
    field = 0;
    FUN_000678d0()->tail();
}