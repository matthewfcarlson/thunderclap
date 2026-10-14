struct Obj_18cb50 {
    char pad[0x10];
    int* GetPtr();
};
int* Obj_18cb50::GetPtr() {
    return (int*)((char*)this + 0x10);
}