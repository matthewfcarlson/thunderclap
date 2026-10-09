struct Temp { char pad[12]; void Init(); int Get(); void Cleanup(); };
unsigned char __cdecl Work(int, Temp*);
struct Receiver { void Send(int); };
unsigned char Target(int a, Receiver* b) {
    Temp t;
    t.Init();
    unsigned char r = Work(a, &t);
    if (b) b->Send(t.Get());
    t.Cleanup();
    return r;
}