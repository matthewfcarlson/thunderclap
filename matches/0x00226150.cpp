extern int gA, gB, gC;
struct V3 {
    int a, b, c;
};
struct Obj {
    char pad[0x12e0];
    int value;
    V3 Get();
};
void Transform(int, V3*);
V3 Obj::Get() {
    V3 t;
    t.a = gA;
    t.b = gB;
    t.c = gC;
    Transform(value, &t);
    return t;
}
