class Obj_15b400 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int x);
};

bool Obj_15b400::Set(int x) {
    mVal = x;
    return true;
}
