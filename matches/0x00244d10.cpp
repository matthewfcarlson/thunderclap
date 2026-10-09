struct Temp {
    char x[12];
    void Init();
    unsigned long Get();
    void Done();
};
extern unsigned char __cdecl F25bce0(int, Temp*);
extern unsigned long long __cdecl F2672f0(unsigned long, int, int);
unsigned char __cdecl Target(int a, unsigned long* out) {
    Temp t;
    t.Init();
    unsigned char r = F25bce0(a, &t);
    if (out) {
        unsigned long g = t.Get();
        unsigned long long v = F2672f0(g, 0, 0);
        ((unsigned long long*)out)[0] = v;
    }
    t.Done();
    return r;
}
