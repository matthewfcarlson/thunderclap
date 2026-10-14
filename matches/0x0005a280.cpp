class Obj_5a280 {
  public:
    char pad[0x34];
    int mVal;
    bool Set(int x);
};

bool Obj_5a280::Set(int x) {
    mVal = x;
    return true;
}
