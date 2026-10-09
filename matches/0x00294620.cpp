struct T { int x, y, z; };
class C {
public:
    void Prep(int* a, T* out);
    void Finish(T t, int d, int e);
    void Target(int a, int b, int c, int d, int e);
};
void C::Target(int a, int b, int c, int d, int e) {
    T t;
    Prep(&a, &t);
    Finish(t, d, e);
}
