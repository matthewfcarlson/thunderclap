class Obj_193760 {
  public:
    char pad[0x13c];
    int mValue;
    bool Set(int value);
};

bool Obj_193760::Set(int value) {
    mValue = value;
    return true;
}
