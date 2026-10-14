extern "C" void _ReadWriteBarrier();
struct Sub_27ff90 {
    void Forward(int a, int b, int c);
};

struct Owner_27ff90 {
    char pad[12];
    Sub_27ff90* m_sub;
    void fn(int a, int b, int c);
};

void Owner_27ff90::fn(int a, int b, int c) {
    m_sub->Forward(a, b, c);
    _ReadWriteBarrier();
}
