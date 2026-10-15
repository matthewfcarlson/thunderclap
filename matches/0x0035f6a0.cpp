struct Pair {
    unsigned a, b;
};
extern Pair __cdecl lookup(const char*, int, int);
extern const char busName[];
extern const char seqName[];
class Registry {
  public:
    void put(Pair*, Pair*, int, int);
};
extern Registry registry;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl init() {
    Pair a = lookup(busName, 0, 0);
    Pair b = lookup(seqName, 0, 0);
    registry.put(&b, &a, 8, 4);
    atexit(cleanup);
}