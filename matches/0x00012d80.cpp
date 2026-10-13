class C {
  public:
    char pad[0x28];
    void* GetThing();
};
void* C::GetThing() {
    return (char*)this + 0x28;
}
