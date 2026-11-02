struct X_213520 {
    char pad[8];
    int* p;
};
extern "C" X_213520* FUN_00213520(X_213520* a, int b) {
    int* q = a->p;
    *q = 1;
    q[1] = (b != 0);
    a->p = (int*)((char*)a->p + 8);
    return a;
}