struct A_15acb0 {
    char pad[0x68];
    int* m;
    int* Get();
};
int* A_15acb0::Get() {
    return (int*)((char*)this + 0x68);
}
