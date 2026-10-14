// STATUS: equivalent (tools/equiv.py level 3: 352 inputs, branch coverage 6/6)
// FUN_00092390 @ 0x00092390
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

int __cdecl FUN_00345475(int c);

class Sink {
public:
    void FUN_001d1dd0(char *text, int arg);
};

void __stdcall FUN_00092390(Sink *sink, const char *src, int arg)
{
    struct Frame {
        char buf[0x40];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    const char *e = src;
    while (*e != 0)
        e++;
    int len = e - src;
    int i;
    for (i = 0; i < len; i++)
        fr.buf[i] = (char)FUN_00345475(src[i]);
    fr.buf[i] = 0;
    sink->FUN_001d1dd0(fr.buf, arg);
    __security_check_cookie(fr.cookie);
}
