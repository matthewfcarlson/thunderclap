extern "C" int __cdecl atexit(void(__cdecl*)());
extern const char name[];
class Obj {
  public:
    void Init(const char*, int);
};
extern Obj globalObj;
void __cdecl cleanup();
void __cdecl FUN_0035faa0() {
    globalObj.Init(name, 0);
    atexit(cleanup);
}