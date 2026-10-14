typedef unsigned int u32_1c5f20;
void __cdecl thunk_FUN_00267090(u32_1c5f20);
class Target_1c5f20 {
  public:
    char pad[4];
    u32_1c5f20 value;
    void run();
};
void Target_1c5f20::run() {
    thunk_FUN_00267090(value);
}