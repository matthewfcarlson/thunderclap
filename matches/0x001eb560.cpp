extern const char s1_1eb560[];
extern const char s2_00424200[];
struct Temp_1eb560 {
    char pad[0x48];
    void Init();
    void SetName(const char*);
    void Finish();
};
struct Obj_1eb560 {};
struct Owner_1eb560 {
    Obj_1eb560* Get();
};
struct Renderer_1eb560 {
    void Draw(Temp_1eb560*, int, int, float);
};
void Build(Obj_1eb560*, Temp_1eb560*);
struct C_1eb560 {
    Renderer_1eb560* m0;
    Owner_1eb560* m4;
    char m8;
    void Fn(int);
};
void C_1eb560::Fn(int t) {
    Temp_1eb560 a;
    a.Init();
    a.SetName(s1_1eb560);
    a.SetName(s2_00424200);
    Obj_1eb560* o = m4->Get();
    if (o)
        Build(o, &a);
    if (m8)
        m0->Draw(&a, 0, t, 100.0f);
    a.Finish();
}