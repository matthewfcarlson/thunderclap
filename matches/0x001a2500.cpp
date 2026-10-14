struct X_1a2500 {
    char pad[0x89];
    char m;
    char Set(char c);
};

char X_1a2500::Set(char c) {
    m = c;
    return 1;
}
