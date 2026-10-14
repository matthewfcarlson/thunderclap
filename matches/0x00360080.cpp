extern "C" void _atexit(void (*)(void));
extern void __cdecl Handler(void);
class Obj_360080 {
  public:
    void Fn();
};
extern Obj_360080 gObj_360080;
void __cdecl Target() {
    gObj_360080.Fn();
    _atexit(Handler);
}
