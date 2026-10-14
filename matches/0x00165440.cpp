class A_165440 {
  public:
    char pad[0x10];
    void* Get10();
};

void* A_165440::Get10() {
    return (char*)this + 0x10;
}
