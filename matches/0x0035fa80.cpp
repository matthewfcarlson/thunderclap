class Obj {
  public:
    void Init(const char*, int);
};
extern Obj gObj;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl FUN_0035fa80() {
    gObj.Init("ListenerEffectGc", 0);
    atexit(cleanup);
}