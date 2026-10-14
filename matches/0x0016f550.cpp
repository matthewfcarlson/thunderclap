class Obj {
  public:
    char pad[0x4c];
    int m4c;
    char Set(int x);
};

char Obj::Set(int x) {
    m4c = x;
    return 1;
}
