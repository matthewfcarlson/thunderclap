struct Sub {
    char data[0x38];
};
struct Obj {
    void* Target();
};
void* Obj::Target() {
    return (void*)((char*)this + 0x38);
}