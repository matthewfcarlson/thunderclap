class Obj_193300 {
  public:
    char pad[0x8c];
    int mValue;
    bool Set(int x);
};

bool Obj_193300::Set(int x) {
    mValue = x;
    return true;
}
