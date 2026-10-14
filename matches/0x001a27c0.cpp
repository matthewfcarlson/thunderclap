class Obj_1a27c0 {
  public:
    char pad[0xe4];
    int value;
    char Set(int x);
};
char Obj_1a27c0::Set(int x) {
    value = x;
    return 1;
}