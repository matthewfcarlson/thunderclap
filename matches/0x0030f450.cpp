class C_30f450 {
  public:
    int pad[2];
    void* ptr;
    int f();
};
int C_30f450::f() {
    if (!ptr)
        return 0;
    return *(int*)((char*)ptr + 0x10);
}