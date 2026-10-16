struct X {
    char pad[8];
    int value;
    void Fn(int x);
    void Other(int, int);
};
void X::Fn(int x) {
    Other(x, value);
}