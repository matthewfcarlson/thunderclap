class Obj_16f250 {
  public:
    void* vptr;
    float f;
    char pad[4];
    int mC;
    char Fn(int x);
};

char Obj_16f250::Fn(int x) {
    mC = x;
    return 1;
}
