class pddiBaseContext {
  public:
    char pad[0x58];
    char* member;
    int vfunc_67();
};
int pddiBaseContext::vfunc_67() {
    return *(int*)(member + 8);
}