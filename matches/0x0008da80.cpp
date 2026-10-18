extern int __cdecl Find(int, const char*);
extern const char visual[];
extern const char logname[];
extern const char lua[];
extern "C" void __stdcall FUN_0008da80(int a, int b) {
    if (Find(b, visual) != 0) {
        if (Find(b, logname) != 0) {
            Find(b, lua);
        }
    }
}