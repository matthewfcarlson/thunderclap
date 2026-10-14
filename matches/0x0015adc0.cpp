class Obj {
  public:
    char pad[24];
    int mField;
    char Fn(int x);
};

char Obj::Fn(int x) {
    mField = x;
    return 1;
}
