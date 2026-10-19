extern "C" double __cdecl asin(double);
float __cdecl FUN_00011010(float value) {
    double result = asin(value);
    return (float)result;
}