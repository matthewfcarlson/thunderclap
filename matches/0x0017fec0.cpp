class Obj_17fec0 {
  public:
    char pad[0x14];
    int mValue;
    bool Set(int x);
};

bool Obj_17fec0::Set(int x) {
    mValue = x;
    return true;
}
