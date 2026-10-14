void Cleanup(void*, void*);
void Release(void*);
struct Obj_2fa050 {
    void* a;
    void* b;
    void Target();
};
void Obj_2fa050::Target() {
    Cleanup(a, b);
    if (a)
        Release(a);
    a = 0;
    b = 0;
}