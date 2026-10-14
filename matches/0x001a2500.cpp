struct X {
    char pad[0x89];
    char m;
    char Set(char c);
};

char X::Set(char c) {
    m = c;
    return 1;
}
