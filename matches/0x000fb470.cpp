extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

class Thing {
public:
    int a[5];
    float value;
    char text[32];
    Thing* Init(const char* s);
};

Thing* Thing::Init(const char* s) {
    strncpy(text, s, 0x20);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    value = 1.0f;
    return this;
}