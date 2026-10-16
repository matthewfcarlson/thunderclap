extern "C" int __cdecl snprintf(char*, unsigned int, const char*, ...);
extern int counter;
extern char buffer[256];
char* FUN_00203740() {
    int n = counter++;
    snprintf(buffer, 256, "unique%d", n);
    return buffer;
}