extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
class Target { char pad[0xaa4]; public: void Copy(char *p); };
void Target::Copy(char *p) { strncpy((char *)this + 0xaa4, p, 0x20); }