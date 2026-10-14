class X_1fd360 {
  public:
    char pad[0x22c];
    int* items;
    int Find(int value);
};
int X_1fd360::Find(int value) {
    int r = -1;
    int i = 0;
    do {
        if (items[i] == value) {
            r = i;
            break;
        }
        ++i;
    } while (i < 0x14);
    return r;
}
