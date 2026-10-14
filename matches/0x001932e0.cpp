class Obj_1932e0 {
  public:
    char pad[0x88];
    int mVal;
    bool Set(int v);
};

bool Obj_1932e0::Set(int v) {
    mVal = v;
    return true;
}
