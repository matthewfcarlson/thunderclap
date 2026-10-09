extern "C" char* __cdecl strchr(const char*, int);

void __stdcall RemoveNewlines(char* text)
{
    char* p;
    char c;
    p = strchr(text, 10);
    while (p != 0) {
        c = *p;
        while (c != 0) {
            *p = p[1];
            ++p;
            c = *p;
        }
        p = strchr(text, 10);
    }
}