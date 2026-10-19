extern int gA, gB, gC;
struct ThisWrap_000e75a0 {
    int inner(int);
    int FUN_000e75a0(int x);
};
extern "C" int __cdecl outer(int, int, int*, int*, int);
int ThisWrap_000e75a0::FUN_000e75a0(int x) {
    return outer(outer(this->inner(x), 0, &gC, &gB, 0), 0, &gB, &gA, 0);
}