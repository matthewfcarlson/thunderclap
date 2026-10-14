class Obj {
  public:
    char Pad[0x14];
    int Member;
    char Target(int);
};
char Obj::Target(int value) {
    Member = value;
    return 1;
}
