class Obj_326f90 {
  public:
    char pad0[0x10];
    int count;
    char pad14[4];
    int delta;
    char pad1c[8];
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    void Fn();
};
void Obj_326f90::Fn() {
    ++count;
    a24 += delta;
    if (a2c)
        a2c += delta;
    if (a28)
        a28 += delta;
    if (a44)
        a44 += delta;
    if (a48)
        a48 += delta;
    if (a30)
        a30 += delta;
    if (a34)
        a34 += delta;
    if (a38)
        a38 += delta;
    if (a3c)
        a3c += delta;
    if (a40)
        a40 += delta;
    if (a50)
        a50 += delta;
    if (a4c)
        a4c += delta;
}