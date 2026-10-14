struct Temp_1eb950 {
    char data[0x48];
    void Init();
    void Add(const char*);
    void Finish();
};
struct Manager_1eb950 {
    int* Get();
};
struct Obj_1eb950 {
    void Send(Temp_1eb950*, int, float, float);
};
struct Owner_1eb950 {
    char pad[4];
    Manager_1eb950* mgr;
    char enabled;
    void Run(float);
};
void Use(int*, Temp_1eb950*);
void Owner_1eb950::Run(float x) {
    Temp_1eb950 t;
    if (enabled) {
        t.Init();
        t.Add("Objects");
        t.Add("DSP");
        int* p = mgr->Get();
        if (p)
            Use(p, &t);
        if (enabled)
            ((Obj_1eb950*)*(void**)this)->Send(&t, 0, x, 100.0f);
        t.Finish();
    }
}
