struct Obj {
    char pad[12];
    int mField;
    char Set(int v);
};

char Obj::Set(int v) {
    mField = v;
    return 1;
}
