struct Temp {
    char pad[12];
    void Init();
    int Value();
    void Cleanup();
    int Finish();
};
extern unsigned char __cdecl Get(int, Temp*);
extern int __cdecl Convert(int, int);
unsigned char Target(int a, int* out) {
    Temp t;
    t.Init();
    unsigned char r = Get(a, &t);
    if (out) {
        int x = t.Finish();
        *out = Convert(x, 0);
    }
    t.Cleanup();
    return r;
}