class Obj_2988e0 {
  public:
    char pad0[0x20];
    unsigned char flag;
    char pad21[3];
    unsigned char* a;
    char pad28[8];
    unsigned char* b;
    char pad34[8];
    int start;
    int end;
    void Clear();
};
void Obj_2988e0::Clear() {
    unsigned int n = (end - start) / 12;
    unsigned int i = 0;
    if (n != 0) {
        do {
            a[i] = 0xff;
            b[i] = 0xff;
            ++i;
        } while (i < n);
    }
    flag = 0;
}