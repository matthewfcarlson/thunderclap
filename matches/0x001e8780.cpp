extern "C" float g_limit;
extern "C" float g_accum;
extern "C" const float g_bias = 4294967296.0f;

extern "C" bool __stdcall FUN_001e8780(int value)
{
    float next = (float)value;
    if (value < 0)
        next += g_bias;
    next += g_accum;
    if (next < g_limit) {
        g_accum = next;
        return true;
    }
    return false;
}