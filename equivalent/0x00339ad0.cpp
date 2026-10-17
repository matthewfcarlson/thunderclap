// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00339ad0 @ 0x00339ad0
extern const char DAT_0043469c[];
extern const char DAT_00428328[];
extern int DAT_004d9a30;
extern "C" void __cdecl FUN_002135a0(int session, int code, const char *message);
extern "C" int __cdecl FUN_00212f00(int session, int code);
extern "C" void __cdecl FUN_00212e20(int session, int code);
extern "C" void __cdecl FUN_002139a0(int session, int first, int second);
extern "C" const char * __cdecl FUN_00213190(int session, int code);
extern "C" int __cdecl FID_conflict__fwprintf(int *stream, const char *format, const char *text);
extern "C" void __cdecl FUN_00212d80(int session, int code);
// equiv-conv: FUN_00339ad0 eax esi
void FUN_00339ad0(int active, int session)
{
    if (!active) return;
    FUN_002135a0(session, -10001, DAT_0043469c);
    int result = FUN_00212f00(session, -1);
    if (result == 6) {
        FUN_00212e20(session, -2);
        FUN_002139a0(session, 1, 0);
    } else {
        const char *message = FUN_00213190(session, -2);
        FID_conflict__fwprintf(&DAT_004d9a30, DAT_00428328, message);
        FUN_00212d80(session, -3);
    }
}