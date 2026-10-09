class Slots {
  public:
    char pad[0xc];
    int values[8];
    void Remove(int);
};
void Slots::Remove(int value) {
    for (int i = 0; i < 8; ++i) {
        if (values[i] == value) {
            values[i] = 0;
            return;
        }
    }
}