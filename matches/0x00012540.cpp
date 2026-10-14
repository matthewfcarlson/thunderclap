struct X_12540 {
    char pad[0x38];
    char* Get();
};

char* X_12540::Get() {
    return (char*)this + 0x38;
}
