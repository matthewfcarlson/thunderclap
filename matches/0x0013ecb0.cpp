class Obj {
  public:
    char Fn(int x);
    char pad[12];
    int mValue;
};

char Obj::Fn(int x) {
    mValue = x;
    return 1;
}
