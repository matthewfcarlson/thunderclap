class Obj_5d500 {
  public:
    char pad[0x2c];
    int mVal;
    bool Set(int x);
};

bool Obj_5d500::Set(int x) {
    mVal = x;
    return true;
}
