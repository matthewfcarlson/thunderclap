typedef unsigned char u8_1f9130;
typedef unsigned int u32_1f9130;
class Ret_1f9130 {
  public:
    void Invoke(u32_1f9130);
};
Ret_1f9130* Make();
class Obj_1f9130 {
  public:
    char pad[4];
    u32_1f9130 a, b, c, d, e, f, g, h;
    u8_1f9130 flag;
    char Check(u32_1f9130);
    char Target(u32_1f9130, u32_1f9130, u32_1f9130, u32_1f9130, u32_1f9130, u32_1f9130, u32_1f9130, u32_1f9130, u32_1f9130, u8_1f9130);
};
char Obj_1f9130::Target(u32_1f9130 p1, u32_1f9130 p2, u32_1f9130 p3, u32_1f9130 p4, u32_1f9130 p5, u32_1f9130 p6, u32_1f9130 p7, u32_1f9130 p8, u32_1f9130 p9, u8_1f9130 p10) {
    char r = Check(p1);
    if (r) {
        a = p2;
        b = p3;
        c = p4;
        d = p5;
        e = p6;
        f = p7;
        g = p8;
        Ret_1f9130* o = Make();
        o->Invoke(h);
        h = p9;
        flag = p10;
    }
    return r;
}