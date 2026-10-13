struct A {
    char pad[0x18];
    void* data;
    void* Get();
};

void* A::Get() {
    return &data;
}