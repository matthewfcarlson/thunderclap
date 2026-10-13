class Obj {
  public:
    char pad[12];
    int m;
    char Set(int arg);
};

char Obj::Set(int arg) {
    m = arg;
    return 1;
}
