class O {
  public:
    char pad[0x38];
    void* Get();
};
void* O::Get() {
    return (char*)this + 0x38;
}
