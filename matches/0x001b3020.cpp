class Obj {
  public:
    char pad0[0x0c];
    int m0c;
    char pad1[0x30 - 0x10];
    int m30;
    int m34;
    Obj() throw();
};

Obj::Obj() throw() {
    m0c = -1;
    m34 = 0;
    m30 = 0;
}
