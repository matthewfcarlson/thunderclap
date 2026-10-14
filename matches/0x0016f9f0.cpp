class Obj {
  public:
    char m[16];
    int m10;
    char Set(int x) throw();
};
char Obj::Set(int x) throw() {
    m10 = x;
    return 1;
}
