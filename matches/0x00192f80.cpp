class Obj_192f80 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int value);
};

bool Obj_192f80::Set(int value) {
    mValue = value;
    return true;
}
