class Thing_1f8740 {
  public:
    char pad[0x440];
    unsigned char bytes[6];
    unsigned char Get(int index);
};
unsigned char Thing_1f8740::Get(int index) {
    unsigned char result = 0;
    if (index >= 0 && index < 6)
        result = bytes[index];
    return result;
}