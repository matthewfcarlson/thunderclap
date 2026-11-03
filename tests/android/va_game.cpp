// Android A0 varargs prototype, game side (docs/native-android.md section 12). Compiled the way the tree is: front end
// for aarch64-pc-windows-msvc (MS ABI, char* va_list) to IR, then retargeted (tests/android/va_proto.sh).
#include <stdarg.h>

extern "C" {
int snprintf(char*, unsigned long long, const char*, ...);                 // host (bionic) variadic, called directly
int hulk_host_vsnprintf_ms(char*, unsigned long long, const char*, va_list);  // host glue taking the game's va_list

// a variadic definition: ints and doubles, in the order `types` gives
double __cdecl game_mix(const char* types, ...) {
    va_list ap;
    va_start(ap, types);
    double s = 0;
    for (const char* t = types; *t; t++)
        s = s * 10 + (*t == 'd' ? va_arg(ap, double) : (double)va_arg(ap, int));
    va_end(ap);
    return s;
}

// va_list consumer inside the game (as equivalent/0x002160c0, Lua's pushvfstring): `%d`, `%f`, `%s` only
int __cdecl game_vfmt(char* out, const char* fmt, va_list ap) {
    char* o = out;
    for (const char* f = fmt; *f; f++) {
        if (*f != '%') { *o++ = *f; continue; }
        char tmp[64];
        f++;
        const char* s = tmp;
        if (*f == 'd') snprintf(tmp, sizeof tmp, "%d", va_arg(ap, int));
        else if (*f == 'f') snprintf(tmp, sizeof tmp, "%.3f", va_arg(ap, double));
        else s = va_arg(ap, const char*);
        while (*s) *o++ = *s++;
    }
    *o = 0;
    return (int)(o - out);
}

// forwarding inside the game (variadic -> va_list), as matches/0x00267760 / 0x00238bb0 do with the x86 `&fmt + 4`
int __cdecl game_fmt(char* out, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int n = game_vfmt(out, fmt, ap);
    va_end(ap);
    return n;
}

// forwarding to the host (vsprintf-like: matches/0x00246f50 -> _vsnprintf)
int __cdecl game_host_fmt(char* out, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int n = hulk_host_vsnprintf_ms(out, 256, fmt, ap);
    va_end(ap);
    return n;
}

// the callers: game -> game variadic (double among them), game -> host variadic with a double
double __cdecl game_call_mix(void) { return game_mix("idid", 1, 2.5, 3, 4.25); }  // ((1*10+2.5)*10+3)*10+4.25 = 1284.25
int __cdecl game_call_fmt(char* out) { return game_fmt(out, "a%db%fc%sd%d", 7, 0.5, "x", -2); }
int __cdecl game_call_host_fmt(char* out) { return game_host_fmt(out, "%d|%.2f|%s|%d|%.1f", 9, 1.25, "y", 3, 2.0); }
int __cdecl game_call_snprintf(char* out) { return snprintf(out, 64, "%d/%.2f/%d", 5, 6.75, 8); }
// many arguments: past the eight registers, so the stack part of both conventions is exercised
double __cdecl game_call_mix_long(void) {
    return game_mix("ididididid", 1, 0.5, 2, 0.25, 3, 0.125, 4, 0.5, 5, 0.25);
}
}
