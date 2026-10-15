extern "C" char* __cdecl get(char*);
extern "C" float __cdecl val(char*);
extern "C" void __cdecl finish(char*, float);
void __cdecl target(char* s) {
    float sum = val(get(s));
    char* p = get(s);
    while (*p) {
        sum += val(p);
        p = get(s);
    }
    finish(s, sum);
}