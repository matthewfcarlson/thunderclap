class Inner_30ed00 {
  public:
    int data[0x15];
    void Init();
};
class Obj_30ed00 {
  public:
    int z[5];
    Inner_30ed00 one;
    Inner_30ed00 two;
    int last;
    Obj_30ed00* Copy(Obj_30ed00* src);
};
Obj_30ed00* Obj_30ed00::Copy(Obj_30ed00* src) {
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