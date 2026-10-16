class Thing {
  public:
    void Init();
};
extern Thing gThing;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void FUN_0035fd90() {
    gThing.Init();
    atexit(cleanup);
}