class Obj_165410 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};

bool Obj_165410::Set(int value) {
    mValue = value;
    return true;
}
