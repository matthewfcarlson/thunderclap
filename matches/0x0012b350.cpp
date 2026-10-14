struct X_12b350 {
    char pad[0x10];
    int m10;
    char Set(int v);
};
char X_12b350::Set(int v) {
    m10 = v;
    return 1;
}
