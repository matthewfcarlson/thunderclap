class Thing {
  public:
    char pad[0x570];
    int slots[2];
    void Remove(int value);
};
void Thing::Remove(int value) {
    for (int i = 0; i < 2; ++i) {
        if (slots[i] == value) {
            slots[i] = 0;
            return;
        }
    }
}