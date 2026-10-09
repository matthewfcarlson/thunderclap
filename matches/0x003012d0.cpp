class C {
  public:
    bool Check(int, int);
    void Pair(int, int);
    void Finish(int, int);
    void Target(int, int);
};

void C::Target(int a, int b) {
    if (!Check(a, b)) {
        Pair(a, b);
        Pair(b, a);
        Finish(a, b);
    }
}