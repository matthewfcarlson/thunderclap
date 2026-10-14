class Obj_192e90 {
  public:
    char pad[0x118];
    int mValue;
    bool Set(int value);
};

bool Obj_192e90::Set(int value) {
    mValue = value;
    return true;
}
