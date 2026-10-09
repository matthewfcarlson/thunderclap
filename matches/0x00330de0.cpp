struct Desc {
    int format;
    char pad[24];
};
extern "C" int __stdcall GetBackBuffer2(int);
extern "C" void __stdcall GetDesc(int, Desc*);
extern "C" void __stdcall Release(int);
extern "C" int __stdcall CreateTexture2(int, int, int, int, int, int, int);
extern "C" int Alloc(int);
struct Obj {
    virtual void Fn();
};
struct Factory {
    Obj* Build(int, int);
};
class Device {
    char pad[0x10];

  public:
    int m;
    char pad2[0x80];
    Obj* texture;
    void Update();
    void Tail();
};
void Device::Update() {
    if (texture == 0) {
        int s = GetBackBuffer2(0);
        Desc d;
        GetDesc(s, &d);
        Release(s);
        int t = CreateTexture2(0x40, 1, 1, 1, 0, d.format, 3);
        Obj* o = (Obj*)Alloc(0xf8);
        if (o)
            o = ((Factory*)o)->Build(m, t);
        else
            o = (Obj*)0;
        texture = o;
        o->Fn();
        Tail();
    }
}