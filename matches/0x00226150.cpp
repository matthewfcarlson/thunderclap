extern int gA_226150, gB, gC;
struct V3_226150 {
    int a, b, c;
};
struct Obj_226150 {
    char pad[0x12e0];
    int value;
    V3_226150 Get();
};
void Transform(int, V3_226150*);
V3_226150 Obj_226150::Get() {
    V3_226150 t;
    t.a = gA_226150;
    t.b = gB;
    t.c = gC;
    Transform(value, &t);
    return t;
}
