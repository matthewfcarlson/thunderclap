class PropActorToPropAction {
    char pad[0x1c];
    void* m;

  public:
    bool vfunc_3(void* a, void* b);
    bool helper();
};
bool PropActorToPropAction::vfunc_3(void* a, void* b) {
    if (*((unsigned char*)m + 0x15) == 0)
        return helper();
    return true;
}