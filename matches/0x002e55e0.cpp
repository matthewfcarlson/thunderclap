struct Row_2e55e0 {
    int* p;
    int pad[2];
};
struct Obj_2e55e0 {
    char pad[0x14];
    Row_2e55e0* mRows;
    bool Parse(int value, int* out);
    int target(int a, int b);
};
int Obj_2e55e0::target(int a, int b) {
    if (Parse(a, &a) == true) {
        return mRows[a].p[b];
    }
    return 0;
}
