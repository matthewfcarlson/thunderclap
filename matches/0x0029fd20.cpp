struct Obj_29fd20 {
    void Method(int v, void* self);
};
extern Obj_29fd20* gObject_29fd20;
struct Caller_29fd20 {
    void Target(int value);
};
void Caller_29fd20::Target(int value) {
    gObject_29fd20->Method(value, this);
}
