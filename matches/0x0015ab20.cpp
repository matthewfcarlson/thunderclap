struct O {
    char pad[0x14];
    int mField;
    char Set(int x);
};
char O::Set(int x) {
    mField = x;
    return 1;
}