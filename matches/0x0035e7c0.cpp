class Registry {
  public:
    void Init(const char*, int);
};
extern Registry gRegistry;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl target() {
    gRegistry.Init("sound/rsd", 0);
    atexit(cleanup);
}