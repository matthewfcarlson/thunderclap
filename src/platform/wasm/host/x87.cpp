// The x87 math the game's code computes with (wasm6; docs/native-float64.md): softx87's transcendental
// instructions and the 80-bit consumers of their results (tools/native_float.py x87ext, applied by
// tools/wasm_port.py fpfix), as on the 64-bit builds. Integer arithmetic only.
#include "../../sdl/crt/softx87.cpp"
#include "../../sdl/host/x87ext_native.cpp"

// A call of a math function that x87ext left alone (no consumer pattern) still gets the instruction's result,
// not the C library's.
extern "C" {
double sin(double x) { return hulk_x87_sin(x); }
double cos(double x) { return hulk_x87_cos(x); }
double tan(double x) { return hulk_x87_tan(x); }
double atan(double x) { return hulk_x87_atan(x); }
double atan2(double y, double x) { return hulk_x87_atan2(y, x); }
double exp(double x) { return hulk_x87_exp(x); }
double log(double x) { return hulk_x87_log(x); }
double log10(double x) { return hulk_x87_log10(x); }
double pow(double x, double y) { return hulk_x87_pow(x, y); }
double asin(double x) { return hulk_x87_asin(x); }
double acos(double x) { return hulk_x87_acos(x); }
}
