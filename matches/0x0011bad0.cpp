struct Obj_11bad0 {
    char pad[12];
    int value;
    char Fn(int a);
};
char Obj_11bad0::Fn(int a) {
    value = a;
    return 1;
}
