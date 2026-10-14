class Device_1b8160 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void Finish();
    virtual void Stop(int);
    virtual float Get();
};
class Thing_1b8160 {
  public:
    char pad[0xc];
    Device_1b8160* device;
    char pad2[0x120];
    unsigned char done;
    float value;
    void Update();
};
void Thing_1b8160::Update() {
    if (device) {
        if (!done) {
            value = device->Get();
            if (device)
                device->Stop(0);
            done = 1;
        }
        device->Finish();
    }
}