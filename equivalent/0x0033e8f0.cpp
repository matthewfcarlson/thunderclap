// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0033e8f0 @ 0x0033e8f0
// FUN_0033e8f0 @ 0x0033e8f0
// equiv-conv: FUN_0033e7f0 eax esi edi
int __cdecl FUN_00213290(void*, int); int __cdecl FUN_00212d70(void*); int __cdecl FUN_0033e7f0(int, void*, void*); int __cdecl FUN_00212fb0(void*,int); void __cdecl FUN_00338d90(void*,int); void __cdecl FUN_00212e20(void*,int); void __cdecl FUN_00213c90(void*,int); void __cdecl FUN_00213c40(void*);
int __cdecl FUN_0033e8f0(void* handle) { int co = FUN_00213290(handle, -10002); int n = FUN_00212d70(handle); int result = FUN_0033e7f0(n, (void*)co, handle); if (result < 0) { if (FUN_00212fb0(handle,-1)) { FUN_00338d90(handle,1); FUN_00212e20(handle,-2); FUN_00213c90(handle,2); } FUN_00213c40(handle); } return result; }
