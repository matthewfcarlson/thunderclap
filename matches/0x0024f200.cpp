extern "C" char hulk_at_004e6748[];
class SeqEventChannelSendVolumes;

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventChannelSendVolumes* f4(unsigned char flags);
};

class SeqEventChannelSendVolumes : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventChannelSendVolumes* f4(unsigned char flags);
};

void __fastcall FUN_0025fd10(void*);
void FUN_00247550(void* g, SeqEventChannelSendVolumes* p);

SeqEventChannelSendVolumes* SeqEventChannelSendVolumes::f4(unsigned char flags) {
    FUN_0025fd10((void*)(this));
    if (flags & 1) {
        FUN_00247550((void*)((int)(hulk_at_004e6748 + 0x8)), this);
    }
    return this;
}
