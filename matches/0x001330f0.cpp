class Obj {
  public:
    char pad[12];
    int mValue;
    char Set(int x);
};
char Obj::Set(int x) {
    mValue = x;
    return 1;
}
