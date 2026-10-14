class X_14c5f0 {
  public:
    char pad[0x10];
    char* Get();
};

char* X_14c5f0::Get() {
    return (char*)((char*)this + 0x10);
}
