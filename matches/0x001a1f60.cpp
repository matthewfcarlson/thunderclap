struct X {
    char pad[0x10];
    int* Get();
};
int* X::Get() {
    return (int*)((char*)this + 0x10);
}