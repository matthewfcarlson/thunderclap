typedef unsigned int size_t;
extern "C" char * __cdecl strncpy(char *, const char *, size_t);
struct DebugConsole;
struct Worker { void run(DebugConsole *, char *); };
struct DebugConsole { char pad0[0x14]; char text[0x80]; char pad94[0x10]; Worker *fieldA4; void vfunc_3(char *); };
void DebugConsole::vfunc_3(char *arg) { fieldA4->run(this, arg); strncpy(text, arg, 0x80); *((char *)this + 0x93) = 0; }
