class Obj {
  public:
    void Do(int, int, int, int);
};
extern "C" Obj* __cdecl FUN_002d6dd0(int);
void __cdecl Target(int a, int b, int c) {
    Obj* p = FUN_002d6dd0(a);
    p->Do(b, c, 1, 1);
}