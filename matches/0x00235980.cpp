struct Obj_235980 {
    char pad[0x10];
    void* Get();
};
void* Obj_235980::Get() {
    char* p = (char*)this + 0x10;
    return p;
}