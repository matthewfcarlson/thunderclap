class Thing_337190 {
  public:
    char pad[0x44];
    int index;
    void* Get();
};
void* Thing_337190::Get() {
    if (index >= 0x18)
        return 0;
    return (char*)this + (index++ * 3 + 9) * 8;
}