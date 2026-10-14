class Obj_68850 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int value);
};

bool Obj_68850::Set(int value) {
    mValue = value;
    return true;
}