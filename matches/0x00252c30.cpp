class SeqAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
class SeqActionVarTempo : public SeqAction { public: void f1(void*); char pad[4]; int field8; int fieldC; };
void SeqActionVarTempo::f1(void* param) {
  *(int*)(*(int*)((char*)param+4)+0x28) = field8 + 0x10;
  *(int*)(*(int*)((char*)param+4)+0x30) = field8 + 8;
  fieldC = 0;
}