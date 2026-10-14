struct Obj_28ac00 {
    char pad[0x18];
    int* arr;
    void helper(int, int*, int*);
    void target(int a, int* out);
};
void Obj_28ac00::target(int a, int* out) {
    int local;
    helper(a, &a, &local);
    *out = arr[a];
}