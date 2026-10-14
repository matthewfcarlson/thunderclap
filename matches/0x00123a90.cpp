class Obj_123a90 {
  public:
    char pad[0x14];
    char m;
    char Set(char x);
};

char Obj_123a90::Set(char x) {
    m = x;
    return 1;
}
