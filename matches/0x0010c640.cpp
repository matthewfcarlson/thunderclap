struct T_10c640 {
    char pad[12];
    int m;
    char SetTimeBegin_0010c640(int x);
};

char T_10c640::SetTimeBegin_0010c640(int x) {
    m = x;
    return 1;
}
