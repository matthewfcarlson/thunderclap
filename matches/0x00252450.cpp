// Same code shape as 0x0024ea80 (propagated; names are from that function)
class SeqAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(int); virtual void f5(); virtual void f6(); };
class SeqActionChannelSendVolumes : public SeqAction { public: int pad; void f4(int); };
void SeqActionChannelSendVolumes::f4(int) { *(int*)((char*)this + 0xc) = 5; }