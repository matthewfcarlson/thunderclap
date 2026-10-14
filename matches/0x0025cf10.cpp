struct Inner_25cf10 {
    void f();
};
struct Obj_25cf10 {
    char pad[0x1c];
    Inner_25cf10 inner;
    Obj_25cf10* target();
};
Obj_25cf10* Obj_25cf10::target() {
    inner.f();
    return this;
}