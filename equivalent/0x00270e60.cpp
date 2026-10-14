// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 8/8)
// FUN_00270e60 @ 0x00270e60
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
int __cdecl FUN_00270c10(const char *);
extern char DAT_0052a0f0;
struct Record_270e60 { char name[0x11c]; };
extern Record_270e60 DAT_00528430[];

void __cdecl FUN_00270e60(const char *key, char *output)
{
    char buffer[17];
    strncpy(buffer, key, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);
    FUN_0026d850(&DAT_0052a0f0);
    int index = FUN_00270c10(buffer);
    if (index == -1) {
        output[0] = 0;
    } else {
        const char *source = DAT_00528430[index].name;
        char value;
        do {
            value = *source++;
            *output++ = value;
        } while (value);
    }
    FUN_0026d840(&DAT_0052a0f0);
}