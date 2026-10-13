struct O {
    char pad[0x1c];
    int m1c;
    char Set(int v);
};
char O::Set(int v) {
    m1c = v;
    return 1;
}
