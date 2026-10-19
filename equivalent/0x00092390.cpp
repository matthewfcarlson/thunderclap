// STATUS: equivalent (tools/equiv.py level 3: 7022 inputs, branch coverage 6/6)
// FUN_00092390 @ 0x00092390
// cl-flags: /GS

int __cdecl FUN_00345475(int c);

class Sink_92390 {
public:
    void FUN_001d1dd0(char *text, int arg);
};

void __stdcall FUN_00092390(Sink_92390 *sink, const char *src, int arg)
{
    struct Frame {
        char buf[0x40];
    } fr;
    const char *e = src;
    while (*e != 0)
        e++;
    int len = e - src;
    int i;
    for (i = 0; i < len; i++)
        fr.buf[i] = (char)FUN_00345475(src[i]);
    fr.buf[i] = 0;
    sink->FUN_001d1dd0(fr.buf, arg);
}
