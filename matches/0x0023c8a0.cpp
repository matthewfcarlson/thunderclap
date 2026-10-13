class C {
  public:
    char pad[12];
    void* Get();
};

void* C::Get() {
    return (char*)this + 12;
}
