class C_12100 {
  public:
    char* Get();
    char pad[0x40];
};
char* C_12100::Get() {
    return (char*)this + 0x40;
}
