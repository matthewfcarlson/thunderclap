class T_12b260 {
  public:
    char pad[12];
    int m;
    bool Set(int x);
};

bool T_12b260::Set(int x) {
    m = x;
    return true;
}
