// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0003ef50 @ 0x0003ef50
typedef unsigned int DWORD;
typedef void (__cdecl *Callback)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD);
void __cdecl FUN_0003ef50(DWORD unused, const DWORD* args, DWORD unused2, Callback callback) {
    callback(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
}