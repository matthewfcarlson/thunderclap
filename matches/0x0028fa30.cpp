struct X {
    int pad;
    unsigned int value;
    unsigned int Get(unsigned int arg);
};
unsigned int X::Get(unsigned int arg) {
    return value;
}