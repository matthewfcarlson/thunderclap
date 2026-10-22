class CWorldStreamManager_204410 {
  public:
    char pad[0x5a4];
    signed char flags[0x400];
    int Find(int index);
};
int CWorldStreamManager_204410::Find(int index) {
    int count = 0;
    int i = 0;
    do {
        if (flags[i] == 1) {
            if (count == index)
                return i;
            ++count;
        }
        ++i;
    } while (i < 0x400);
    return -1;
}