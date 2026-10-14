struct Data_221c60 {
    unsigned int a[16];
};
class C_221c60 {
  public:
    Data_221c60 d;
    char pad[0x10];
    int x;
    void Copy(C_221c60*);
};
void C_221c60::Copy(C_221c60* src) {
    d = src->d;
    x = 2;
}