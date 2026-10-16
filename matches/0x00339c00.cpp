extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl helper(void*, const char*, unsigned int, const char*);
void __cdecl target(void* p, const char* s) {
    helper(p, s, strlen(s), s);
}
