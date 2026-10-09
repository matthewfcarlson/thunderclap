class Obj {
  public:
    char pad[0x610];
    int entries[0x401];
    void put(int value);
};
void Obj::put(int value) {
    int i = 0;
    do {
        if (entries[i - 1] == 0)
            break;
        if (entries[i] == 0) {
            i++;
            break;
        }
        if (entries[i + 1] == 0) {
            i += 2;
            break;
        }
        if (entries[i + 2] == 0) {
            i += 3;
            break;
        }
        i += 4;
    } while (i < 0x400);
    if (i != 0x400)
        entries[i - 1] = value;
}
