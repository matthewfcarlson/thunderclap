class C_1d72e0 {
  public:
    char pad[0xa0];
    void* p;
    int get();
};
int C_1d72e0::get() {
    if (p)
        return *(int*)((char*)p + 0x10);
    return 0;
}