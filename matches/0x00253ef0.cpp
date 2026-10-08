class SeqAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
class SeqActionStream : public SeqAction { char pad[0x1c]; public: virtual void f4(int); };
void SeqActionStream::f4(int) { *(int*)((char*)this + 0x20) = 5; }