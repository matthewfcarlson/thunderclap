// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002fd730 @ 0x002fd730
struct Temp { unsigned int FUN_0030f100(); };
struct Obj { void* context; char data[24]; unsigned char flag; char pad1[3]; char output[64]; unsigned int value; void FUN_002fd730(); };
Temp* __fastcall FUN_0030edf0(void* context);
void __cdecl FUN_002ef760(void* output, unsigned int result, float scale, unsigned int value, void* data);
void Obj::FUN_002fd730() {
    if (!flag) {
        unsigned int originalValue = value;
        void* originalData = data;
        flag = 1;
        Temp* a = FUN_0030edf0(context);
        unsigned int b = a->FUN_0030f100();
        FUN_002ef760(output, b, 1.0f, originalValue, originalData);
    }
}