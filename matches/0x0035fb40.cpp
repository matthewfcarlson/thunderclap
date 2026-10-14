extern void __cdecl FUN_00364330();
extern void __cdecl _atexit(void (*)(void));
class Obj_35fb40 {
  public:
    void Run();
};
extern Obj_35fb40 g_4e6628;
void __cdecl FUN_0035fb40() {
    g_4e6628.Run();
    _atexit(FUN_00364330);
}
