extern char data[];
extern __int64 result;
extern __int64 __cdecl getValue(const char*);
void target() {
    result = getValue(data);
}