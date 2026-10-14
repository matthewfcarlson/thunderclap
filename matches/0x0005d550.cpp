class Obj_5d550 {
  public:
    char pad[0x3a];
    char mVal;
    char Set(char c);
};
char Obj_5d550::Set(char c) {
    mVal = c;
    return 1;
}
