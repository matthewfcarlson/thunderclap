// Same code shape as 0x00221c60 (propagated; names are from that function)
struct Data_30f120 {
    unsigned int a[16];
};
class C_30f120 {
  public:
    Data_30f120 d;
    char pad[0x10];
    int x;
    void Copy(C_30f120*);
};
void C_30f120::Copy(C_30f120* src) {
    d = src->d;
    x = 2;
}