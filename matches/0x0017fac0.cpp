struct Thing {
    char pad[0x44];
    float value;
    unsigned char Set(float angle);
};
unsigned char Thing::Set(float angle) {
    value = angle * 0.0174532925f;
    return 1;
}
