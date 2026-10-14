class Obj_47f90 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
char Obj_47f90::Set(int x) {
    value = x;
    return 1;
}
