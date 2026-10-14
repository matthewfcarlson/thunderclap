class X_2987d0 {
  public:
    char pad0[0x20];
    unsigned char count;
    char pad21[3];
    unsigned char* buffer;
    char pad28[8];
    unsigned char* output;
    char pad34[8];
    int* entries;
    void f(unsigned char);
};
void X_2987d0::f(unsigned char v) {
    unsigned int i = v;
    if (entries[i * 3 + 2] && buffer[i] == 0xff) {
        buffer[i] = count;
        output[count] = v;
        ++count;
    }
}