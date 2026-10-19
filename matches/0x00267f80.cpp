typedef unsigned int DWORD;
struct LARGE_INTEGER {
    DWORD low;
    DWORD high;
};
extern "C" int __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
extern "C" int __cdecl Convert(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
extern DWORD freqLow, freqHigh;
int Timer() {
    LARGE_INTEGER n;
    QueryPerformanceCounter(&n);
    return Convert(n.low, n.high, 1000, 0, freqLow, freqHigh);
}
