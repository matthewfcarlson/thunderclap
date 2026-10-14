struct Sub_12940 {
    char data[0x38];
};
struct Obj_12940 {
    void* Target();
};
void* Obj_12940::Target() {
    return (void*)((char*)this + 0x38);
}