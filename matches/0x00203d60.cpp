class C_203d60 {
    char pad[0x578];

  public:
    int Get(int index);
};
int C_203d60::Get(int index) {
    return *(int*)((char*)this + 0x578 + index * 4);
}