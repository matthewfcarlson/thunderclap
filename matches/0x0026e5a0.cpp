extern "C" char *_strncpy(char *, const char *, unsigned int);
class Obj {
public:
    void Target(unsigned int a, char *src, unsigned int b, unsigned int d);
    void Send(void *p, int n);
};
void Obj::Target(unsigned int a, char *src, unsigned int b, unsigned int d) {
    struct Buf {
        unsigned int h;
        unsigned int a;
        unsigned int b;
        unsigned int d;
        char s[83];
        char z;
    } buf;
    buf.a = a;
    buf.b = b;
    buf.h = 6;
    buf.d = d;
    _strncpy(buf.s, src, 0x54);
    buf.z = 0;
    Send(&buf, 100);
}
