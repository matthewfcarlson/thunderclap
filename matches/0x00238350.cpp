typedef float(__cdecl* Callback)(unsigned int, unsigned int);
extern Callback gFunction;
extern unsigned int gValue;
extern const float gZero;
float __cdecl FUN_00238350(unsigned int param) {
    if (gFunction == 0)
        return gZero;
    return gFunction(param, gValue);
}