class O_12bd0 {
  public:
    char pad[0x38];
    void* Get();
};
void* O_12bd0::Get() {
    return (char*)this + 0x38;
}
