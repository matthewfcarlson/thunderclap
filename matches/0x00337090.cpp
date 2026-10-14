class Thing_337090 {
  public:
    char pad[0x44];
    int count;
    void* Get(int);
};
void* Thing_337090::Get(int i) {
    if (i >= 0 && i < count)
        return (void*)((char*)this + (i * 3 + 9) * 8);
    return 0;
}