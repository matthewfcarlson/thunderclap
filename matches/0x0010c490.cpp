class Obj_10c490 {
  public:
    char pad[0x1c];
    char mVal;
    char Set(char c);
};
char Obj_10c490::Set(char c) {
    mVal = c;
    return 1;
}
