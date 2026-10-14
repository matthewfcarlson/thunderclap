extern "C" void _atexit(void (*)(void));
extern void __cdecl Handler(void);
class Obj {
  public:
    void Fn();
};
extern Obj gObj;
void __cdecl Target() {
    gObj.Fn();
    _atexit(Handler);
}
