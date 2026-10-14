class O_18ecc0 {
  public:
    char pad[0x10];
    int* Get();
};
int* O_18ecc0::Get() {
    return (int*)((char*)this + 0x10);
}
