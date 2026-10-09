class Thing {
  public:
    char pad[0x44];
    int index;
    void* Get();
};
void* Thing::Get() {
    if (index >= 0x18)
        return 0;
    return (char*)this + (index++ * 3 + 9) * 8;
}