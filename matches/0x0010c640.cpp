struct T_10c640 {
    char pad[12];
    int m;
    char Set(int x);
};

char T_10c640::Set(int x) {
    m = x;
    return 1;
}
