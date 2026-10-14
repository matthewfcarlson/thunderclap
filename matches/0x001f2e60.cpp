struct Sub_1f2e60 {
    void f();
};
struct Obj_1f2e60 {
    char pad[0x18];
    void run();
};
void Obj_1f2e60::run() {
    ((Sub_1f2e60*)((char*)this + 0x10))->f();
    ((Sub_1f2e60*)((char*)this + 8))->f();
    ((Sub_1f2e60*)this)->f();
}