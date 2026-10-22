extern "C" int __cdecl atexit(void(__cdecl*)());
extern const char name[];
class MetaType_35faa0 {
  public:
    void Init(const char*, int);
};
extern MetaType_35faa0 globalObj;
void __cdecl cleanup();
void __cdecl FUN_0035faa0() {
    globalObj.Init(name, 0);
    atexit(cleanup);
}