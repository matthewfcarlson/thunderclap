extern "C" struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
extern "C" Pair result;
void FUN_0035e320() {
    result = FUN_0027b020("random_intersect");
}