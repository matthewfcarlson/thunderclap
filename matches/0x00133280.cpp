class Obj_133280 {
  public:
    char pad[0x20];
    int mVal;
    bool Set(int x);
};

bool Obj_133280::Set(int x) {
    mVal = x;
    return true;
}
