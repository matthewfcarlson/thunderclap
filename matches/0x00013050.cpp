struct A_13050 {
    char pad[0x34];
    int* Get();
};

int* A_13050::Get() {
    return (int*)((char*)this + 0x34);
}
