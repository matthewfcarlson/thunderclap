struct Thing_d6fd0 {
    char pad[8];
    char* p;
    char GetByte();
};

char Thing_d6fd0::GetByte() {
    return p[4];
}
