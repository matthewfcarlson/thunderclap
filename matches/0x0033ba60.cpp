extern "C" int __cdecl Count(void*);
extern "C" float __cdecl Score(void*, int);
extern "C" void __cdecl Set(void*, float);
int __cdecl Target(void* p) {
    int n = Count(p);
    float best = Score(p, 1);
    for (int i = 2; i <= n; ++i) {
        float v = Score(p, i);
        if (v < best)
            best = v;
    }
    Set(p, best);
    return 1;
}