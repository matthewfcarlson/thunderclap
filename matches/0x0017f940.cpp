struct X {
    char pad[0x18];
    unsigned char value;
    unsigned char Get();
};
unsigned char X::Get() {
    return value;
}