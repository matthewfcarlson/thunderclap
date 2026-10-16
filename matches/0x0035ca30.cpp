struct Pair {
    int a;
    int b;
};
extern Pair __cdecl lookup(const char*);
extern Pair result;
void __cdecl FUN_0035ca30() {
    result = lookup("squad");
}