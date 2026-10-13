class Obj {
  public:
    char pad[0x1c];
    int m1c;
    char SetVal(int x);
};

char Obj::SetVal(int x) {
    m1c = x;
    return 1;
}
