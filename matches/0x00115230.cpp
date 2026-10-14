class Obj_115230 {
  public:
    char pad[0x18];
    int mVal;
    bool Set(int v);
};

bool Obj_115230::Set(int v) {
    mVal = v;
    return true;
}
