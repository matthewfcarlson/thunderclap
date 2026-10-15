typedef __int64 I64;
extern const char nameA[], nameB[];
extern I64 __cdecl make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager {
    void setup(I64*, I64*, int, int);
};
extern Manager globalManager;
void __cdecl FUN_00360380() {
    I64 a = make(nameA, 0, 0);
    I64 b = make(nameB, 0, 0);
    globalManager.setup(&b, &a, 16, 4);
    atexit(cleanup);
}