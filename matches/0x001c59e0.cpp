struct Elem_1c59e0 {
    void f(int);
};
struct Obj_1c59e0 {
    char pad[0x10];
    unsigned int limit;
    char pad2[4];
    int count;
    int* items;
    void target(int);
};
void Obj_1c59e0::target(int arg) {
    int n = count;
    for (int i = 0; i <= n; ++i) {
        if ((unsigned)i < limit && items[i] != 0)
            ((Elem_1c59e0*)items[i])->f(arg);
    }
}