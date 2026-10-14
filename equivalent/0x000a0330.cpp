// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_000a0330 @ 0x000a0330
// Wrap an angle in degrees into [0, 360). NaN and values beyond +-3600 give 0.
extern "C" int __cdecl _isnan(double);

union FloatBits {
    float f;
    unsigned int u;
};

float FUN_000a0330(float degrees)
{
    if (_isnan(degrees)) {
        return 0.0f;
    }
    FloatBits magnitude;
    magnitude.f = degrees;
    magnitude.u &= 0x7fffffff;
    if (magnitude.f > 3600.0f) {
        return 0.0f;
    }
    while (degrees < 0.0f) {
        degrees += 360.0f;
    }
    while (degrees >= 360.0f) {
        degrees -= 360.0f;
    }
    return degrees;
}
