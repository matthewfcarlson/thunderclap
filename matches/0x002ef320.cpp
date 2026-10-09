class SimState {
  public:
    virtual void vfunc_7();
    char pre[0x4c];
    char pad[0x40];
};
void SimState::vfunc_7() {
    *(int*)(pad + 0x08) = 0;
    *(int*)(pad + 0x04) = 0;
    *(int*)(pad + 0x00) = 0;
    *(int*)(pad + 0x14) = 0;
    *(int*)(pad + 0x10) = 0;
    *(int*)(pad + 0x0c) = 0;
    *(int*)(pad + 0x30) = 0;
}