class Obj_17fc60 {
  public:
    char Pad[0x14];
    int Member;
    char Target(int);
};
char Obj_17fc60::Target(int value) {
    Member = value;
    return 1;
}
