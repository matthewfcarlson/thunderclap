extern "C" int F212f00(void* L, int i);
extern "C" void F339d70(void* L, int i, int t);
extern "C" void F339c30(void* L, int i, const char* m);
extern "C" int F339010(void* L, int i, const char* e);
extern "C" void F338e20(void* L, const char* m);
extern "C" void F212d80(void* L, int i);
extern "C" void F2138e0(void* L, int i);
int Target(void* L) {
    int t = F212f00(L, 2);
    F339d70(L, 1, 5);
    if (t != 0 && t != 5)
        F339c30(L, 2, "nil or table expected");
    if (F339010(L, 1, "__metatable"))
        F338e20(L, "cannot change a protected metatable");
    F212d80(L, 2);
    F2138e0(L, 1);
    return 1;
}
