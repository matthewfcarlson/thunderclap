struct Target {
    char data[0x51];
    char Set(char v);
};
char Target::Set(char v) {
    data[0x50] = v;
    return 1;
}
