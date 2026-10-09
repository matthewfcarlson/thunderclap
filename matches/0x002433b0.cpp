extern "C" bool __cdecl Check(const void *, const void *);
int __cdecl Target(const void *a, const char *b) {
    if (!Check(a, b)) goto fail;
    if (!Check(a, b + 4)) goto fail;
    if (Check(a, b + 8)) goto success;
fail:
    return 0;
success:
    return 1;
}