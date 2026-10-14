class Obj_60470 {
  public:
    char pad[0x20];
    int m20;
    bool Set(int v);
};

bool Obj_60470::Set(int v) {
    m20 = v;
    return true;
}
