struct Sub {
    void f();
};
struct Obj {
    char pad[0x18];
    void run();
};
void Obj::run() {
    ((Sub*)((char*)this + 0x10))->f();
    ((Sub*)((char*)this + 8))->f();
    ((Sub*)this)->f();
}