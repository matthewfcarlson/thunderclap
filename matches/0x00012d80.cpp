class C_12d80 {
  public:
    char pad[0x28];
    void* GetThing();
};
void* C_12d80::GetThing() {
    return (char*)this + 0x28;
}
