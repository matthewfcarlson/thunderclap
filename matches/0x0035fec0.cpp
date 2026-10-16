class Thing {
  public:
    Thing();
};
extern Thing gThing;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void init() {
    gThing.Thing::Thing();
    atexit(cleanup);
}