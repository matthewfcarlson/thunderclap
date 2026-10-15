struct Obj {
    int first;
    char names[0x280];
    int values[10];
    char flags[10];
    Obj();
};
Obj::Obj() {
    first = 0;
    for (int i = 0; i < 10; ++i) {
        names[i * 64] = 0;
        values[i] = 0;
        flags[i] = 's';
    }
}