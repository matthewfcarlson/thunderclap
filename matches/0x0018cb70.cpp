class Obj_18cb70 {
  public:
    char pad[0x1c];
    int value;
    char Set(int x);
};
char Obj_18cb70::Set(int x) {
    value = x;
    return 1;
}
