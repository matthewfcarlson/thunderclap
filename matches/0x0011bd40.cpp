class Obj_11bd40 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
char Obj_11bd40::Set(int x) {
    value = x;
    return 1;
}