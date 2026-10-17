// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003397c0 @ 0x003397c0
// equiv-conv: FUN_00213190 edi
extern "C" int __cdecl FUN_00213190(void*);
extern "C" int* __cdecl FUN_00347ba4();
extern "C" const char* __cdecl FUN_00347b53(int);
extern "C" void __cdecl FUN_00213470(void*, const char*, int, const char*);
extern "C" void __cdecl FUN_00212de0(void*, void*);

// equiv-conv: FUN_003397c0 edi ebx
int FUN_003397c0(void* stream, void* context)
{
    int error = FUN_00213190(stream) + 1;
    int code = *FUN_00347ba4();
    const char* description = FUN_00347b53(code);
    FUN_00213470(stream, "cannot read %s: %s", error, description);
    FUN_00212de0(stream, context);
    return 2;
}
