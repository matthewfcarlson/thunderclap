class Obj {
  public:
    char Set(int);
    char pad[12];
    int mValue;
};

char Obj::Set(int arg) {
    mValue = arg;
    return 1;
}
