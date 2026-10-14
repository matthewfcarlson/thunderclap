class Obj {
    char pad[12];

  public:
    int mValue;
    char Set(int x);
};
char Obj::Set(int x) {
    mValue = x;
    return 1;
}