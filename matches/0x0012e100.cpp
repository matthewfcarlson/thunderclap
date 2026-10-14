struct Obj_12e100 {
    char pad[12];
    int mField;
    char Set(int v);
};

char Obj_12e100::Set(int v) {
    mField = v;
    return 1;
}
