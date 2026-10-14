class Obj {
  public:
    char Set(int x);
    char pad[12];
    int mField;
};

char Obj::Set(int x) {
    mField = x;
    return 1;
}
