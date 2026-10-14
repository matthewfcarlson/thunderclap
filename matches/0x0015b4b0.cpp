class Obj_15b4b0 {
  public:
    char pad[0x5c];
    int mVal;
    bool Set(int v);
};

bool Obj_15b4b0::Set(int v) {
    mVal = v;
    return true;
}
