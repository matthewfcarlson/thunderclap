class Obj_47e40 {
  public:
    char pad[0x10];
    int mVal;
    bool Set(int v);
};

bool Obj_47e40::Set(int v) {
    mVal = v;
    return true;
}
