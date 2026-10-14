struct O_10c5d0 {
    char pad[0x1c];
    int m1c;
    char Set(int v);
};
char O_10c5d0::Set(int v) {
    m1c = v;
    return 1;
}
