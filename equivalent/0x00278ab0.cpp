// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::XboxSaveDrive::vfunc_17 @ 0x00278ab0
namespace core { struct XboxSaveDrive { char pad[0xb4]; int result; char more[0x26]; char letter; bool FUN_002788c0(); int FUN_002787c0(int); int vfunc_17(int); }; }
extern "C" void __cdecl FUN_0026b800(char *, int, int, int, int, int, int);
extern "C" int __stdcall FUN_003563f0(char *, char *);
int core::XboxSaveDrive::vfunc_17(int value) {
    if (!FUN_002788c0()) return 0;
    char path[4];
    char buffer[0x200];
    path[0] = letter; path[1] = ':'; path[2] = '\\'; path[3] = 0;
    FUN_0026b800(buffer, 2, value, 1, 0, 0x202, 0);
    int error = FUN_003563f0(path, buffer);
    if (error) { result = FUN_002787c0(error); return 0; }
    result = 0;
    return 1;
}