class O_12080 {
    char pad[0x20];

  public:
    void* Get();
};
void* O_12080::Get() {
    return (char*)this + 0x20;
}
