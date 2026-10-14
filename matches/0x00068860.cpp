class Obj_68860 {
  public:
    char pad[0x10];
    unsigned int m10;
    unsigned char Set(unsigned int v);
};

unsigned char Obj_68860::Set(unsigned int v) {
    m10 = v;
    return 1;
}
