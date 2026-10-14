class Obj_204ea0 {
  public:
    virtual void a();
    virtual void release();
};
class Inner_204ea0 {
  public:
    void dispose();
};
class A_204ea0 {
  public:
    char p0[4];
    unsigned char a, b;
    char p1[0x20];
    short value;
    char p2[4];
    void* ptr2c;
    Obj_204ea0* obj30;
    char p3[4];
    Inner_204ea0* ptr38;
    void close();
};
extern void fvalue(int);
extern void fptr(void*);
void A_204ea0::close() {
    if (ptr38) {
        ptr38->dispose();
        ptr38 = 0;
    }
    if (obj30)
        fvalue((int)value);
    if (obj30) {
        obj30->release();
        obj30 = 0;
    }
    if (ptr2c) {
        fptr(ptr2c);
        ptr2c = 0;
    }
    a = 0;
    b = 0;
    value = 0;
}
