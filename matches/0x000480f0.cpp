class Obj {
  public:
    int pad[4];
    int m;
    bool f(int x);
};

bool Obj::f(int x) {
    m = x;
    return true;
}
