class X_1b32b0 {
  public:
    char pad[0x34];
    int count;
    int items[1];
    bool Has(int value);
};
bool X_1b32b0::Has(int value) {
    int i = 0;
    if (count > 0) {
        while (i < count) {
            if (items[i] == value)
                return true;
            ++i;
        }
    }
    return false;
}