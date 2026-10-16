extern "C" __int64 __cdecl findMacro(const char*);
extern "C" __int64 macroValue;
extern "C" void __cdecl FUN_0035d6c0() {
    macroValue = findMacro("$MACRO_DEFINE");
}