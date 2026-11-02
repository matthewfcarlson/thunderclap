extern "C" int FUN_00096600(const char*, const char*);
extern "C" int FUN_001d54c0(const char* s) {
    int r = 0;
    if (!FUN_00096600(s, "minor"))
        r = 1;
    else if (!FUN_00096600(s, "medium"))
        r = 2;
    else if (!FUN_00096600(s, "major"))
        r = 3;
    else if (!FUN_00096600(s, "major_only_on_destruction"))
        r = 4;
    return r;
}
