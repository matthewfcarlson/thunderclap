class O {
    char pad[0x18];

  public:
    void* Get();
};
void* O::Get() {
    return (char*)this + 0x18;
}
