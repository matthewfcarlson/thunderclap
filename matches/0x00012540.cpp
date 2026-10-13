struct X {
    char pad[0x38];
    char* Get();
};

char* X::Get() {
    return (char*)this + 0x38;
}
