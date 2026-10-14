extern "C" int __cdecl atexit(void (*)(void));
extern "C" void __cdecl FUN_003644d0();
class Obj {
  public:
    void Run();
};
extern Obj gTarget;
void __cdecl FUN_003606d0() {
    gTarget.Run();
    atexit(FUN_003644d0);
}
