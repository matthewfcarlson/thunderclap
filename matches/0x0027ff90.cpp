extern "C" void _ReadWriteBarrier();
struct Sub {
    void Forward(int a, int b, int c);
};

struct Owner {
    char pad[12];
    Sub* m_sub;
    void fn(int a, int b, int c);
};

void Owner::fn(int a, int b, int c) {
    m_sub->Forward(a, b, c);
    _ReadWriteBarrier();
}
