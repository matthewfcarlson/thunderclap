class Obj_48070 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int arg);
};

bool Obj_48070::Set(int arg) {
    mValue = arg;
    return true;
}
