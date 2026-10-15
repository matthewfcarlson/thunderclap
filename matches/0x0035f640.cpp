extern "C" unsigned __int64 __cdecl hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
extern const char name1[];
extern const char name2[];
class Registry {
  public:
    void init(unsigned __int64*, unsigned __int64*, int, int);
};
extern Registry registry;
void function() {
    unsigned __int64 a = hash(name1, 0, 0);
    unsigned __int64 b = hash(name2, 0, 0);
    registry.init(&b, &a, 64, 4);
    atexit(cleanup);
}