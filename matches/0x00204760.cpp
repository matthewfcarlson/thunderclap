class Thing_204760 {
  public:
    char pad[0x570];
    int slots[2];
    void Remove(int value);
};
void Thing_204760::Remove(int value) {
    for (int i = 0; i < 2; ++i) {
        if (slots[i] == value) {
            slots[i] = 0;
            return;
        }
    }
}