class Obj {
  public:
    char mFlag;
    char pad[0x27];
    int m28;
    char Set(int x);
};

char Obj::Set(int x) {
    m28 = x;
    return 1;
}
