struct X {
    int pad[3];
    int m;
    char Set(int v);
};

char X::Set(int v) {
    m = v;
    return 1;
}
