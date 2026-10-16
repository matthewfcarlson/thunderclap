class Obj {
  public:
    void Init(const char*, int);
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
void __cdecl target() {
    gObj.Init("sound/rsd", 0);
    atexit(Cleanup);
}