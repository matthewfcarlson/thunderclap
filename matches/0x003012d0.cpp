class C_3012d0 {
  public:
    bool Check(int, int);
    void Pair(int, int);
    void Finish(int, int);
    void Target(int, int);
};

void C_3012d0::Target(int a, int b) {
    if (!Check(a, b)) {
        Pair(a, b);
        Pair(b, a);
        Finish(a, b);
    }
}