struct Obj_235980 {
    char pad[0x10];
    void* GetParent_00235980();
};
void* Obj_235980::GetParent_00235980() {
    char* p = (char*)this + 0x10;
    return p;
}