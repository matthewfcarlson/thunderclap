// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00238bb0 @ 0x00238bb0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
typedef int (__cdecl *SinkFn)(int, int, const char*, int);
extern SinkFn DAT_004e5c30;
extern int DAT_004e5c34;
int __cdecl FUN_00267730(char* buf, int size, const char* fmt, char* args);

int __cdecl FUN_00238bb0(int a1, int a2, const char* fmt, ...)
{
    struct Frame {
        char buf[0x400];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    FUN_00267730(fr.buf, 0x400, fmt, (char*)(&fmt + 1));
    if (!DAT_004e5c30) {
        __security_check_cookie(fr.cookie);
        return -1;
    }
    int result = DAT_004e5c30(a1, a2, fr.buf, DAT_004e5c34);
    __security_check_cookie(fr.cookie);
    return result;
}
