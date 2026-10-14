class A_11ce0 {
  public:
    char pad[0x18];
    void* Get();
};
void* A_11ce0::Get() {
    return (char*)this + 0x18;
}
