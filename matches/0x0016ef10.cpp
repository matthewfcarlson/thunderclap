struct Base_16ef10 {
    virtual void f();
    char pad[32];
};
struct Obj_16ef10 : Base_16ef10 {
    char* Get();
};
char* Obj_16ef10::Get() {
    return (char*)((char*)this + 0x20);
}
