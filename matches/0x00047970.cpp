// Same code shape as 0x00011070 (propagated; names are from that function)
extern "C" int __cdecl _isnan(double);
void FUN_00011070(float param_1)
{
    _isnan((double)param_1);
}