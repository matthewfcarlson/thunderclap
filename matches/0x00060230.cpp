class Obj_60230 {
  public:
    char pad[0x14];
    int m;
    char Fn(int x);
};

char Obj_60230::Fn(int x) {
    m = x;
    return 1;
}
