struct Pair_361050 {
    int a, b;
};
extern "C" Pair_361050 __cdecl lookup(const char*, int, int);
struct Obj_361050 {
    void init(Pair_361050*, Pair_361050*, int, int);
};
extern Obj_361050 global_361050;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl FUN_00361050() {
    Pair_361050 a = lookup("HalVoiceChannel", 0, 0);
    Pair_361050 b = lookup("Runtime_Hal", 0, 0);
    global_361050.init(&b, &a, 128, 4);
    atexit(cleanup);
}