struct Obj_1655c0 {
    char pad[0x10];
    int* ptr;
    int* Get();
};
int* Obj_1655c0::Get() {
    return (int*)((char*)this + 0x10);
}
