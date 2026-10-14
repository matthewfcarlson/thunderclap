struct A_1470c0 {
    char pad[0x18];
    void* data;
    void* Get();
};

void* A_1470c0::Get() {
    return &data;
}