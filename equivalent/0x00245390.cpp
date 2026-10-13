// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 34/36, incomplete)
// FUN_00245390 @ 0x00245390
class Stream {
public:
    virtual void v0();
    virtual int v1();
    virtual void *v2();
    virtual void v3();
    virtual unsigned int v4();
    virtual void v5();
    virtual void v6(unsigned int a, unsigned int b, unsigned int c);
    virtual void v7();
    virtual bool v8(unsigned int *out);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};

void FUN_00245380();
Stream *FUN_0025bec0(Stream *s);
void *FUN_0025d340(void *a, unsigned int n, int z);
bool FUN_0025d070(void *buf, unsigned int done, unsigned int left, int z, unsigned int *x3, unsigned int *x2, unsigned int *x1);
void FUN_0025d0f0(void *buf, unsigned int n);
bool FUN_0025d010(void *buf);

void *FUN_00245390(Stream *s, void (*pump)())
{
    if (!pump)
        pump = FUN_00245380;

    if (s->v1() == 0) {
        s->v0();
        while (s->v1() == 1) {
            s->v11();
            pump();
        }
        if (s->v1() != 2) {
            s->v12();
            return 0;
        }
    }

    s = FUN_0025bec0(s);
    if (s->v1() == 0) {
        s->v0();
        while (s->v1() == 1) {
            s->v11();
            pump();
        }
        if (s->v1() != 2) {
            s->v12();
            return 0;
        }
    }

    unsigned int total = s->v4();
    if (total == 0) {
        s->v12();
        return 0;
    }
    void *buf = FUN_0025d340(s->v2(), total, 0);
    if (!buf) {
        s->v12();
        return 0;
    }
    unsigned int left = total;
    unsigned int x1, x2, x3, got;
    while (left != 0) {
        if (FUN_0025d070(buf, total - left, left, 0, &x3, &x2, &x1)) {
            s->v6(x3, x2, x1);
            while (!s->v8(&got)) {
                s->v11();
                pump();
            }
            FUN_0025d0f0(buf, got);
            while (!FUN_0025d010(buf))
                pump();
            left -= got;
        } else {
            pump();
        }
    }
    s->v12();
    return buf;
}
