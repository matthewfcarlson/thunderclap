int Cmp(const char*, const char*);
int Fn(const char* s) {
    int r = 0;
    if (!Cmp(s, "minor"))
        r = 1;
    else if (!Cmp(s, "medium"))
        r = 2;
    else if (!Cmp(s, "major"))
        r = 3;
    else if (!Cmp(s, "major_only_on_destruction"))
        r = 4;
    return r;
}
