class Obj_23cb40 {
  public:
    char pad[12];
    unsigned char value;
    char Set(unsigned char b);
};

char Obj_23cb40::Set(unsigned char b) {
    value = b;
    return 1;
}