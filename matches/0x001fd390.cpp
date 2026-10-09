extern "C" int strcmp(const char*, const char*);
int __stdcall FindName(const char* s) {
    if (s) {
        if (strcmp(s, "rooftop") == 0)
            return 1;
        if (strcmp(s, "intersection") == 0)
            return 2;
        if (strcmp(s, "pasture") == 0)
            return 3;
        if (strcmp(s, "canyon") == 0)
            return 4;
        return ((strcmp(s, "military") != 0) - 1 & 6) - 1;
    }
    return -1;
}