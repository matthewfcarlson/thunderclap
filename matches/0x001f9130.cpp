typedef unsigned char u8;
typedef unsigned int u32;
class Ret {
  public:
    void Invoke(u32);
};
Ret* Make();
class Obj {
  public:
    char pad[4];
    u32 a, b, c, d, e, f, g, h;
    u8 flag;
    char Check(u32);
    char Target(u32, u32, u32, u32, u32, u32, u32, u32, u32, u8);
};
char Obj::Target(u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7, u32 p8, u32 p9, u8 p10) {
    char r = Check(p1);
    if (r) {
        a = p2;
        b = p3;
        c = p4;
        d = p5;
        e = p6;
        f = p7;
        g = p8;
        Ret* o = Make();
        o->Invoke(h);
        h = p9;
        flag = p10;
    }
    return r;
}