struct Pair {
    int a;
    int b;
};
extern Pair __cdecl Find(const char*);
extern Pair result;
void FUN_0035daf0() {
    result = Find("ClearAfterEntry");
}