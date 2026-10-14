class Obj_115290 {
  public:
    char pad[0xc];
    int mVal;
    bool Set(int x);
};

bool Obj_115290::Set(int x) {
    mVal = x;
    return true;
}
