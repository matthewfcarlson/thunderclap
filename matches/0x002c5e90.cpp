struct Input {
    char pad[20];
    int v;
    float f;
};
extern void __cdecl work(float, float*, int, int, int, int);
struct Thing {
    int a, b, c, d;
    void fn(Input*, float);
};
void Thing::fn(Input* in, float x) {
    work(x * 0.25f, &in->f, a, (b = in->v), c, d);
}