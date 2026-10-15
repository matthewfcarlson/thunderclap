typedef unsigned int DWORD;
struct LARGE_INTEGER {
    DWORD low;
    DWORD high;
};
extern "C" int __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
extern "C" void __cdecl Convert(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
extern DWORD freqLow, freqHigh;
void Timer() {
    LARGE_INTEGER n;
    QueryPerformanceCounter(&n);
    Convert(n.low, n.high, 1000, 0, freqLow, freqHigh);
}
