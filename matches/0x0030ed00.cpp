class Inner {
  public:
    int data[0x15];
    void Init();
};
class Obj {
  public:
    int z[5];
    Inner one;
    Inner two;
    int last;
    Obj* Copy(Obj* src);
};
Obj* Obj::Copy(Obj* src) {
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    z[4] = 0;
    one.Init();
    two.Init();
    one = src->one;
    two = src->two;
    last = src->last;
    return this;
}