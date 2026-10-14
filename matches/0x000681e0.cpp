class Obj_681e0 {
  public:
    bool Set(int value);
    char pad[0x30];
    int mValue;
};

bool Obj_681e0::Set(int value) {
    mValue = value;
    return true;
}
