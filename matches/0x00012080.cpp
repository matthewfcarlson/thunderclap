class O {
    char pad[0x20];

  public:
    void* Get();
};
void* O::Get() {
    return (char*)this + 0x20;
}
