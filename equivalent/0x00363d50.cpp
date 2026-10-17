// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 4/4)
// FUN_00363d50 @ 0x00363d50
extern "C" void __cdecl FUN_0008d330(void *);
extern "C" int DAT_004ddab4[];
void FUN_00363d50()
{
    for (int i = 0; i < 13; ++i) {
        int pos = -2 - i * 2;
        void *p = (void *)DAT_004ddab4[pos];
        if (p) {
            FUN_0008d330(p);
            DAT_004ddab4[pos - 1] = 0;
            DAT_004ddab4[pos] = 0;
        }
    }
}