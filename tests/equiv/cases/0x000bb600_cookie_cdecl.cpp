struct Big { int first; char rest[0x2b4]; void FUN_001d1630(); };
struct Registry { void FUN_001d3b00(const char*, Big); };
extern "C" unsigned int DAT_004d9968;
extern "C" void __cdecl __security_check_cookie(unsigned int);
extern "C" Registry* __cdecl FUN_001d4c90();
void FUN_000bb600(){
  unsigned int cookie = DAT_004d9968;
  Registry* reg = FUN_001d4c90();
  if (reg) {
    Big moves;
    moves.FUN_001d1630();
    moves.first = 0;
    reg->FUN_001d3b00("UpdateMoveList", moves);
  }
  __security_check_cookie(cookie);
}
