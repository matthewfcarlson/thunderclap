typedef unsigned int U;
extern char* GetText(U);
extern U Operate(U);
U __cdecl Target(U param) {
    char* p = GetText(param);
    if (*p == 't') {
        U result = (U)GetText(param);
        Operate(param);
        return result;
    }
    Operate(param);
    return (U)GetText(param);
}