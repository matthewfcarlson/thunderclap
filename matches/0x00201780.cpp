extern int gCount;
extern __int64 gPairs[];
extern int gValues[];
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
extern "C" int __cdecl FUN_00201780(int x) {
    __int64 n = FUN_002672f0(x, 0, 0);
    int answer = -1;
    for (int i = 0; i < gCount; ++i) {
        if (gPairs[i] == n) {
            answer = gValues[i];
            break;
        }
    }
    return answer;
}