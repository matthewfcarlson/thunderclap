class Obj_2f2730 {
  public:
    char pad[8];
    int m8;
    int mc;
    char pad2[0x18 - 0x10];
    int m18;
    int m1c;
    void Fn(int v);
};

void Obj_2f2730::Fn(int v) {
    int t = m18;
    m1c = v;
    m8 = t;
    mc = v;
}
