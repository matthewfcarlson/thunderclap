class Thing_1c7f80 {
  public:
    char pad[0x20];
    unsigned int count;
    char pad2[8];
    unsigned int* values;
    unsigned int Get(unsigned int i);
};
unsigned int Thing_1c7f80::Get(unsigned int i) {
    if (i < count)
        return values[i];
    return 0;
}