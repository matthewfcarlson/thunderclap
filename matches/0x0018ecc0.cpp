class O {
  public:
    char pad[0x10];
    int* Get();
};
int* O::Get() {
    return (int*)((char*)this + 0x10);
}
