class SeqAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(int); virtual void f4(); virtual void f5(); virtual void f6(); };
class SeqActionWaitBeat : public SeqAction { public: void f3(int); };
void SeqActionWaitBeat::f3(int) { *(int*)((char*)this + 0xc) = 2; }