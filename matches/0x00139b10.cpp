class Obj_139b10 {
  public:
    char pad[0x34];
    char m34;
    char Set(char b);
};

char Obj_139b10::Set(char b) {
    m34 = b;
    return 1;
}