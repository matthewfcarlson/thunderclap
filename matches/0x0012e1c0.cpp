struct Obj {
    char pad[12];
    int m;
    char Fn(int v);
};

char Obj::Fn(int v) {
    m = v;
    return 1;
}