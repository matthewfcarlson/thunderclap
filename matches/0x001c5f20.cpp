typedef unsigned int u32;
void __cdecl thunk_FUN_00267090(u32);
class Target {
  public:
    char pad[4];
    u32 value;
    void run();
};
void Target::run() {
    thunk_FUN_00267090(value);
}