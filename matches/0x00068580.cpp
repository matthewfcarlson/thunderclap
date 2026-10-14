class Obj_68580 {
  public:
    char pad[12];
    int mVal;
    bool Set(int v);
};

bool Obj_68580::Set(int v) {
    mVal = v;
    return true;
}
