extern "C" __int64 __cdecl lookup(const char*, int, int);
extern const char beat[], sequence[];
class Object {
  public:
    void init(__int64*, __int64*, int, int);
};
extern Object global;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl target() {
    __int64 a = lookup(beat, 0, 0);
    __int64 b = lookup(sequence, 0, 0);
    global.init(&b, &a, 8, 4);
    atexit(cleanup);
}