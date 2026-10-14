class Obj_61d50 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int value);
};

bool Obj_61d50::Set(int value) {
    mValue = value;
    return true;
}