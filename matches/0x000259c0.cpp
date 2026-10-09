// Same code shape as 0x00018990 (propagated; names are from that function)
extern "C" double sqrt(double);
float __fastcall FUN_00018990(float* p) {
    return (float)sqrt((double)(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]));
}
