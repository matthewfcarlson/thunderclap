void Init();
class Obj_222050 {
  public:
    char pad[0x40];
    volatile int a, b, c, d, e;
    Obj_222050();
};
Obj_222050::Obj_222050() {
    Init();
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}