struct State {
    char pad[0x4c];
    unsigned char flag;
    char pad2[3];
    int a;
    int b;
    int c;
    void Fn(unsigned char, int, int, int);
};
extern void __fastcall SetRenderState(unsigned int state, unsigned int value);
extern unsigned int table[];
extern unsigned int g0, g1, g2, g3;
void State::Fn(unsigned char flag, int a, int b, int c) {
    if (flag != this->flag) {
        this->flag = flag;
        SetRenderState(0x40304, flag);
        g0 = flag;
    }
    if (this->flag) {
        if (a != this->a) {
            this->a = a;
            SetRenderState(0x40350, a);
            g3 = a;
        }
        if (b != this->b) {
            this->b = b;
            unsigned int v = table[b];
            SetRenderState(0x40344, v);
            g1 = v;
        }
        if (c != this->c) {
            this->c = c;
            unsigned int v = table[c];
            SetRenderState(0x40348, v);
            g2 = v;
        }
    }
}