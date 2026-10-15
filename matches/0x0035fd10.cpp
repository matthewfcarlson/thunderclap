typedef unsigned __int64 U64;
extern const char name1[], name2[];
extern U64 __cdecl lookup(const char*, int, int);
class Registry {
  public:
    void init(U64*, U64*, int, int);
};
extern Registry registry;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl target() {
    U64 a = lookup(name1, 0, 0);
    U64 b = lookup(name2, 0, 0);
    registry.init(&b, &a, 16, 4);
    atexit(cleanup);
}