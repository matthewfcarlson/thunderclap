class Obj_11bfc0 {
  public:
    char pad[0x34];
    char m34;
    char Set(char c);
};

char Obj_11bfc0::Set(char c) {
    m34 = c;
    return 1;
}