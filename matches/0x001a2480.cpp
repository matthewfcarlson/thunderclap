class Obj_1a2480 {
  public:
    char pad[0x79];
    char m79;
    char Set(char c);
};

char Obj_1a2480::Set(char c) {
    m79 = c;
    return 1;
}
