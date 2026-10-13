// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0008d910 @ 0x0008d910
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int cookie);
extern void __cdecl FUN_0026b800(char* output, int zero, const char* input, int one, int delimiter, int capacity, int last);
extern bool __cdecl FUN_0008d880(const char*, const char*);
bool __cdecl FUN_0008d910(const char* name)
{
    unsigned int cookie = DAT_004d9968;
    bool result = false;
    char buffer[256];
    if (name) {
        FUN_0026b800(buffer, 0, name, 1, '.', 256, 0);
        result = FUN_0008d880(buffer, ".rcf") ||
                 FUN_0008d880(buffer, ".RCF") ||
                 FUN_0008d880(buffer, "rcfs.txt") ||
                 FUN_0008d880(buffer, "dsstdfx.bin") ||
                 FUN_0008d880(buffer, "rsdeffects.bin");
    }
    __security_check_cookie(cookie);
    return result;
}