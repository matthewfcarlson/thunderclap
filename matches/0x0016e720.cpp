struct Obj_16e720 {
    char pad[12];
    int m;
    bool Set(int x);
};
bool Obj_16e720::Set(int x) {
    m = x;
    return true;
}
