class Obj_115520 {
    char pad[0x20];
    int mValue;

  public:
    bool Set(int value);
};

bool Obj_115520::Set(int value) {
    mValue = value;
    return true;
}
