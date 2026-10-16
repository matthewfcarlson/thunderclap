extern "C" int check(const char*, const char*);
int __cdecl target(const char* s) {
    return check(s, "/lua");
}