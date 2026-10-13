class Obj {
  public:
    char pad[12];
    int mValue;
    char Fn(int value);
};

char Obj::Fn(int value) {
    mValue = value;
    return 1;
}
