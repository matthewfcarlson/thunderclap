struct X_1a1f60 {
    char pad[0x10];
    int* Get();
};
int* X_1a1f60::Get() {
    return (int*)((char*)this + 0x10);
}