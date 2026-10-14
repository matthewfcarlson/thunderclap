class Obj_6b370 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int v);
};

bool Obj_6b370::Set(int v) {
    mVal = v;
    return true;
}
