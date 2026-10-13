struct Base {
    virtual void f();
    char pad[32];
};
struct Obj : Base {
    char* Get();
};
char* Obj::Get() {
    return (char*)((char*)this + 0x20);
}
