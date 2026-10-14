extern void __cdecl FUN_00267760(char*, int, const char*, const char*);
struct Sub_1f8f40 {
    void call(const char*);
};
class Target_1f8f40 {
    char pad[8];

  public:
    void run(const char*);
};
extern const char fmt_1f8f40[];
void Target_1f8f40::run(const char* arg) {
    ((Sub_1f8f40*)((char*)this + 8))->call(arg);
    FUN_00267760((char*)this + 0x41c, 0x20, fmt_1f8f40, arg);
}