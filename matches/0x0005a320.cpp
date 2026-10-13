class O {
  public:
    char pad[0x28];
    void* Get();
};
void* O::Get() {
    return (char*)this + 0x28;
}