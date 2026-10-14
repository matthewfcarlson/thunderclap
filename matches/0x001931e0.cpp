struct Sub {
    char pad[0x75];
    char m75;
    char Set(char v);
};

char Sub::Set(char v) {
    m75 = v;
    return 1;
}
