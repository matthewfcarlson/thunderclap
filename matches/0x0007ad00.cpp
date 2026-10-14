struct Obj_7ad00 {
    char pad[0x3800];
    int vals[1];
    int helper(int);
    int target(int);
};
int Obj_7ad00::target(int arg) {
    int i = helper(arg);
    if (i >= 0)
        return vals[i];
    return 0;
}