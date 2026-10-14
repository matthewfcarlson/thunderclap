class Obj_15b290 {
  public:
    char pad[0xc0];
    int mValue;
    char Fn(int value);
};

char Obj_15b290::Fn(int value) {
    mValue = value;
    return 1;
}
