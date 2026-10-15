typedef __int64 I64;
extern "C" I64 __cdecl getid(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
extern char label[];
class Registry {
  public:
    void init(I64*, I64*, int, int);
};
extern Registry registry;
void __cdecl target() {
    I64 a = getid(label, 0, 0);
    I64 b = getid(label, 0, 0);
    registry.init(&b, &a, 12, 4);
    atexit(cleanup);
}