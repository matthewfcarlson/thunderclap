struct Temp_244d10 {
    char x[12];
    void Init();
    unsigned long Get();
    void Done();
};
extern "C" unsigned char __cdecl FUN_0025bce0(int, Temp_244d10*);
extern "C" unsigned long long __cdecl FUN_002672f0(unsigned long, int, int);
unsigned char __cdecl Target(int a, unsigned long* out) {
    Temp_244d10 t;
    t.Init();
    unsigned char r = FUN_0025bce0(a, &t);
    if (out) {
        unsigned long g = t.Get();
        unsigned long long v = FUN_002672f0(g, 0, 0);
        ((unsigned long long*)out)[0] = v;
    }
    t.Done();
    return r;
}
