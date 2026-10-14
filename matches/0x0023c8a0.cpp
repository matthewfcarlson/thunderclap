class C_23c8a0 {
  public:
    char pad[12];
    void* Get();
};

void* C_23c8a0::Get() {
    return (char*)this + 12;
}
