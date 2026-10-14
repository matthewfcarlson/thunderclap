class Obj_192820 {
  public:
    char Pad[0x18];
    int value;
    char Set(int x);
};

char Obj_192820::Set(int x) {
    value = x;
    return 1;
}
