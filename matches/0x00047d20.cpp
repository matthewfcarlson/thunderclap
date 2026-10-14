class Obj_47d20 {
  public:
    char pad[12];
    int mValue;
    char Fn(int value);
};

char Obj_47d20::Fn(int value) {
    mValue = value;
    return 1;
}
