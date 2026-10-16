class Thing {
  public:
    Thing();
    ~Thing();
};
extern Thing gThing;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_00360f60() {
    gThing.Thing::Thing();
    atexit(cleanup);
}