extern "C" int __cdecl _isnan(double);
extern "C" int FUN_00011070(float value) {
    return _isnan((double)value);
}