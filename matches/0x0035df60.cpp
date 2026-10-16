extern const char text[];
extern "C" __int64 parse(const char*);
extern "C" __int64 result;
void target() {
    result = parse(text);
}
