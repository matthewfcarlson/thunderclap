class Obj_15b730 {
  public:
    char pad[0x44];
    int mVal;
    bool Set(int v);
};

bool Obj_15b730::Set(int v) {
    mVal = v;
    return true;
}
