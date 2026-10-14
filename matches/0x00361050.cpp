struct Pair {
    int a, b;
};
extern "C" Pair __cdecl lookup(const char*, int, int);
struct Obj {
    void init(Pair*, Pair*, int, int);
};
extern Obj global;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl FUN_00361050() {
    Pair a = lookup("HalVoiceChannel", 0, 0);
    Pair b = lookup("Runtime_Hal", 0, 0);
    global.init(&b, &a, 128, 4);
    atexit(cleanup);
}