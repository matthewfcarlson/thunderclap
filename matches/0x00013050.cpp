struct A {
    char pad[0x34];
    int* Get();
};

int* A::Get() {
    return (int*)((char*)this + 0x34);
}
