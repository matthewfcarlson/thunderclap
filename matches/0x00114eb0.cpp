struct Obj {
    char pad[12];
    char mVal;
    char Set(char v);
};
char Obj::Set(char v) {
    mVal = v;
    return 1;
}
