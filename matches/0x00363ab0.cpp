typedef unsigned int size_t;
class Obj {
  public:
    void Init(void*, int);
};
extern Obj gObj;
extern char gBuf[];
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl target() {
    gObj.Init(gBuf, 0x8000);
    atexit(cleanup);
}