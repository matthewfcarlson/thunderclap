class Decoder {
  public:
    void* Decode(void*);
};
struct Q {
    unsigned int a, b, c, d;
};
class Channel {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, float*, void*);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[0x10];
    short* indices;
    char* data;
};
void Channel::f3(int index, float* time, void* out) {
    short v = indices[index];
    *time = (float)(int)v;
    char local[16];
    Q* p = (Q*)((Decoder*)(data + index * 6))->Decode(local);
    *(Q*)out = *p;
}