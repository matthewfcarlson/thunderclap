class Obj_115670 {
  public:
    char pad[0x2c];
    int mValue;
    bool Set(int value);
};

bool Obj_115670::Set(int value) {
    mValue = value;
    return true;
}
