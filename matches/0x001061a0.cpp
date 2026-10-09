class C {
public:
    char pad0[0x10];
    char *data;
    int count;
    void f(int index, int a, float b, float c, int d, float e, float f);
};
void C::f(int index, int a, float b, float c, int d, float e, float f) {
    if (index < count) {
        int off = index * 36;
        *(int *)(data + off + 12) = a;
        *(float *)(data + off + 20) = b;
        *(float *)(data + off + 24) = c;
        *(int *)(data + off + 32) = d;
        *(float *)(data + off + 28) = e;
        *(float *)(data + off + 16) = f;
    }
}
