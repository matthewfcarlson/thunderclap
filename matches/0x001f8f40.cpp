extern void __cdecl FUN_00267760(char*, int, const char*, const char*);
struct Sub {
    void call(const char*);
};
class Target {
    char pad[8];

  public:
    void run(const char*);
};
extern const char fmt[];
void Target::run(const char* arg) {
    ((Sub*)((char*)this + 8))->call(arg);
    FUN_00267760((char*)this + 0x41c, 0x20, fmt, arg);
}