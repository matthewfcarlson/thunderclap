class Device { char pad[0x154]; public: void Read(void*, int, int*, void*); };
class Mid { char pad[0x154]; public: Device* dev; };
class Base { public: virtual void f0(); virtual void f1(void*, int*, void*); Mid* mMid; };
void Base::f1(void* a, int* r, void* c) {
 Device* d=mMid->dev;
 d->Read(c,(r[3]-r[1])*(r[2]-r[0])*4,r,a);
}