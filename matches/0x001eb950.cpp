struct Temp {
    char data[0x48];
    void Init();
    void Add(const char*);
    void Finish();
};
struct Manager {
    int* Get();
};
struct Obj {
    void Send(Temp*, int, float, float);
};
struct Owner {
    char pad[4];
    Manager* mgr;
    char enabled;
    void Run(float);
};
void Use(int*, Temp*);
void Owner::Run(float x) {
    Temp t;
    if (enabled) {
        t.Init();
        t.Add("Objects");
        t.Add("DSP");
        int* p = mgr->Get();
        if (p)
            Use(p, &t);
        if (enabled)
            ((Obj*)*(void**)this)->Send(&t, 0, x, 100.0f);
        t.Finish();
    }
}
