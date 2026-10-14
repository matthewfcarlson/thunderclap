class Obj_16f800 {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};

bool Obj_16f800::Set(int v) {
    mVal = v;
    return true;
}