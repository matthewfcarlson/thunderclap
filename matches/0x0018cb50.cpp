struct Obj {
    char pad[0x10];
    int* GetPtr();
};
int* Obj::GetPtr() {
    return (int*)((char*)this + 0x10);
}