extern "C" char DAT_004dc950[];
extern "C" char DAT_004dc96c[];
extern "C" char DAT_004dc988[];
class C {
  public:
    void init(void*, void*);
};
extern "C" void __cdecl FUN_00363bf0(void) {
    ((C*)((int)DAT_004dc988))->init((void*)0x66930, (void*)((int)DAT_004dc988));
    ((C*)((int)DAT_004dc96c))->init((void*)0x66a00, (void*)((int)DAT_004dc96c));
    ((C*)((int)DAT_004dc950))->init((void*)0x66930, (void*)((int)DAT_004dc950));
}