extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Obj {
  public:
    void Init(const char*, int);
};
extern Obj gObj;
void initSound() {
    gObj.Init("sound/rsd", 0);
    atexit(cleanup);
}