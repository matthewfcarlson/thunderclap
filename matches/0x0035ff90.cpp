extern "C" int __stdcall FUN_0024fd10(void*);
extern "C" int atexit(void (*)(void));
class Holder {
  public:
    int Run();
};
extern "C" void __cdecl FUN_003643c0();
extern "C" void __cdecl FUN_0035ff90() {
    ((Holder*)0x4e68f8)->Run();
    atexit(FUN_003643c0);
}
