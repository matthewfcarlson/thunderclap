struct Target {
    char pad[0x284];
    unsigned int value;
    unsigned int Get();
};
unsigned int Target::Get() {
    return value;
}