struct Row {
    int* p;
    int pad[2];
};
struct Obj {
    char pad[0x14];
    Row* mRows;
    bool Parse(int value, int* out);
    int target(int a, int b);
};
int Obj::target(int a, int b) {
    if (Parse(a, &a) == true) {
        return mRows[a].p[b];
    }
    return 0;
}
