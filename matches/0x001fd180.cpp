class C_1fd180 {
  public:
    char pad0[0x214];
    int* a[6];
    int* slots;
    int last;
    void Set(int);
};
void C_1fd180::Set(int value) {
    int i;
    int found = -1;
    for (i = 0; i < 20; i++) {
        if (slots[i] == value) {
            found = i;
            break;
        }
        if (slots[i] == -1)
            found = i;
    }
    last = found;
    if (found != -1) {
        a[0][found * 2] = 0;
        a[1][found * 2] = 0;
        a[2][found * 2] = 0;
        a[3][found * 2] = 0;
        a[4][found * 2] = 0;
        a[5][found * 2] = 0;
        slots[found] = value;
    }
}