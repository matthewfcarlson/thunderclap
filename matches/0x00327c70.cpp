extern "C" int __cdecl strcmp(const char*, const char*);
typedef int(__cdecl* Handler)(int, const char*, int);
struct Entry {
    char name[64];
    Handler handler;
    int context;
};
extern int DAT_005555c0;
extern Entry DAT_005555c8[];
extern Handler DAT_00555608;
int __cdecl FUN_00327c70(int first, const char* name, int context) {
    int count = DAT_005555c0;
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, DAT_005555c8[i].name) == 0) {
            int replacement = DAT_005555c8[i].context;
            if (replacement)
                context = replacement;
            return DAT_005555c8[i].handler(first, name, context);
        }
    }
    return DAT_00555608(first, name, context);
}