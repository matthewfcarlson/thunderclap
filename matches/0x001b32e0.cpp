class Thing_1b32e0 {
    char pad[0x34];
    int count;
    int vals[64];

  public:
    void Add(int value);
};
void Thing_1b32e0::Add(int value) {
    if (count < 0x40) {
        vals[count] = value;
        ++count;
    }
}