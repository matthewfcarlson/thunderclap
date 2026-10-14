class Device_320160 {
    char pad[0x154];

  public:
    void Read(void*, int, int*, void*);
};
class Mid_320160 {
    char pad[0x154];

  public:
    Device_320160* dev;
};
class Base_320160 {
  public:
    virtual void f0();
    virtual void f1(void*, int*, void*);
    Mid_320160* mMid;
};
void Base_320160::f1(void* a, int* r, void* c) {
    Device_320160* d = mMid->dev;
    d->Read(c, (r[3] - r[1]) * (r[2] - r[0]) * 4, r, a);
}