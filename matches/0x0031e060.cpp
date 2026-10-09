class pddiBaseContext {
    char pad[0x58];
    void* member;

  public:
    void vfunc_72(int);
};
void pddiBaseContext::vfunc_72(int value) {
    *(int*)((char*)member + 0x14) = value;
}