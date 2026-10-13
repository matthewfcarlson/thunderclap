struct Obj {
    char pad[0x10];
    int* ptr;
    int* Get();
};
int* Obj::Get() {
    return (int*)((char*)this + 0x10);
}
