class SeqAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(int); virtual void f4(); virtual void f5(); virtual void f6(); };
class SeqActionStream : public SeqAction { public: char pad[0x20 - sizeof(SeqAction)]; int state; void f3(int); };
extern int FUN_0024afe0(int);
extern void FUN_0024c160(int);
void SeqActionStream::f3(int p) { int v = *(int*)((char*)p + 0x34); int x = FUN_0024afe0(v); if (x == 2) { v = *(int*)((char*)p + 0x34); FUN_0024c160(v); } state = 4; }