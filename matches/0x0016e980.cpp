class Obj_16e980 {
  public:
    char pad[0x60];
    int m60;
    bool Set(int v);
};

bool Obj_16e980::Set(int v) {
    m60 = v;
    return true;
}
