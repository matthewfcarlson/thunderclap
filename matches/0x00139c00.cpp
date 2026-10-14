class X_139c00 {
  public:
    char pad[0x28];
    void* Get();
};
void* X_139c00::Get() {
    return (char*)this + 0x28;
}