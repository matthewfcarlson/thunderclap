class O_5a320 {
  public:
    char pad[0x28];
    void* Get();
};
void* O_5a320::Get() {
    return (char*)this + 0x28;
}