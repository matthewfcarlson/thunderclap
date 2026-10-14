class Obj {
  public:
    void* vptr;
    float f;
    char pad[4];
    int mC;
    char Fn(int x);
};

char Obj::Fn(int x) {
    mC = x;
    return 1;
}
