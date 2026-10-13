class O {
  public:
    char pad[0x10];
    void* Get();
};
void* O::Get() {
    return (char*)this + 0x10;
}