struct A {
    char pad[0x68];
    int* m;
    int* Get();
};
int* A::Get() {
    return (int*)((char*)this + 0x68);
}
