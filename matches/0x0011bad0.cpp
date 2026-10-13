struct Obj {
    char pad[12];
    int value;
    char Fn(int a);
};
char Obj::Fn(int a) {
    value = a;
    return 1;
}
