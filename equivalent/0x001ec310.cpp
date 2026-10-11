// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001ec310 @ 0x001ec310
struct Ctx { int FUN_0008a2d0(); int FUN_000897f0(); };
struct Provider { Ctx* FUN_00086310(); };
struct Sink { void FUN_001eb060(int, int); };
struct Cursor { void FUN_001f3950(float); };
struct Model { Cursor* cursor; Sink* sink; void FUN_001efa40(int, int, int); };
struct S {
  Model* model; Provider* prov; unsigned char active; char pad[3]; float value;
  void FUN_001ec310(int);
};
extern "C" unsigned char DAT_004e36e0;
extern "C" unsigned int DAT_004d9968;
extern "C" void __cdecl __security_check_cookie(unsigned int);
void S::FUN_001ec310(int){
  unsigned int cookie = DAT_004d9968;
  if (!DAT_004e36e0 && active) {
    Ctx* c = prov->FUN_00086310();
    Sink* sk = model->sink;
    int a = c->FUN_0008a2d0();
    int b = c->FUN_000897f0();
    sk->FUN_001eb060(b, a);
    a = c->FUN_0008a2d0();
    b = c->FUN_000897f0();
    model->FUN_001efa40(1, b, a);
    float v = value;
    if (0.0f <= v && v <= 100.0f) model->cursor->FUN_001f3950(v);
    DAT_004e36e0 = 1;
  }
  __security_check_cookie(cookie);
}
