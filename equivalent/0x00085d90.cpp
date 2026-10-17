// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00085d90 @ 0x00085d90
extern char DAT_0049bfc8[];
extern int DAT_0049c0c8;

bool __cdecl FUN_00085d90()
{
    int sum = 0;
    const signed char* text = (const signed char*)DAT_0049bfc8;
    while (*text) {
        sum += *text;
        ++text;
    }
    return sum == DAT_0049c0c8;
}
