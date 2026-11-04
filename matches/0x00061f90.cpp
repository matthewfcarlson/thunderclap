class Obj_61f90 {
  public:
    char pad[0x0c];
    int m;
    char SetEvent_00061f90(int x);
};
char Obj_61f90::SetEvent_00061f90(int x) {
    m = x;
    return 1;
}
