struct O_15ab20 {
    char pad[0x14];
    int mField;
    char Set(int x);
};
char O_15ab20::Set(int x) {
    mField = x;
    return 1;
}