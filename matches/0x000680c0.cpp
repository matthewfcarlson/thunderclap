struct Target_680c0 {
    char data[0x51];
    char Set(char v);
};
char Target_680c0::Set(char v) {
    data[0x50] = v;
    return 1;
}
