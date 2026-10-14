class C_92860 {
  public:
    unsigned char Get(int i);
};
unsigned char C_92860::Get(int i) {
    return *((unsigned char*)(((char**)this)[i]) + 8);
}