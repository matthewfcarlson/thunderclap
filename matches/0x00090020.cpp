extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int g_cookie;

void __cdecl FUN_00090020()
{
    volatile unsigned int value = g_cookie;
    __security_check_cookie(value);
}