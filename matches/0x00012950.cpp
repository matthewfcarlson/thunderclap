class C_12950 {
  public:
    char pad[0x40];
    void* Get();
};
void* C_12950::Get() {
    return (char*)this + 0x40;
}