struct X {
    char pad[8];
    int value;
    int Fn(int x);
    int Other(int, int);
};
int X::Fn(int x) {
    return Other(x, value);
}