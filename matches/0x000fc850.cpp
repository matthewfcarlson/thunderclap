class Obj {
  public:
    char pad[16];
    char a, b, c, d;
    float x;
    int Test();
};
int Obj::Test() {
    if ((!c && !(x < 0.1f) && !a) || !d) {
        if (!b)
            return 0;
    }
    return 1;
}