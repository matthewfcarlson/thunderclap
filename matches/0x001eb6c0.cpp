extern const char s1[];
extern const char s2[];
struct Temp {
    char pad[0x48];
    void Init();
    void SetName(const char*);
    void Finish();
};
struct Obj {};
struct Owner {
    Obj* Get();
};
struct Renderer {
    void Draw(Temp*, int, int, float);
};
void Build(Obj*, Temp*);
struct C {
    Renderer* m0;
    Owner* m4;
    char m8;
    void Fn(int);
};
void C::Fn(int t) {
    Temp a;
    a.Init();
    a.SetName(s1);
    a.SetName(s2);
    Obj* o = m4->Get();
    if (o)
        Build(o, &a);
    if (m8)
        m0->Draw(&a, 0, t, 100.0f);
    a.Finish();
}