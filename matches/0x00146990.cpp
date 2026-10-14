class Obj_146990 {
  public:
    char pad[0xc];
    int mValue;
    bool Set(int value);
};

bool Obj_146990::Set(int value) {
    mValue = value;
    return true;
}
