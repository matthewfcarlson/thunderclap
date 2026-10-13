struct T {
    char pad[12];
    int m;
    char Set(int x);
};

char T::Set(int x) {
    m = x;
    return 1;
}
