class Obj_68550 {
  public:
    char pad[0xc];
    int value;
    char Set(int x);
};
char Obj_68550::Set(int x) {
    value = x;
    return 1;
}
