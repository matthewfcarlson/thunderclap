class X_12920 {
  public:
    char pad[0x28];
    void* Get();
};

void* X_12920::Get() {
    return (char*)this + 0x28;
}
