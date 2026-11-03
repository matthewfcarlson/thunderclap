// Android A0 varargs prototype, host side (native ABI, built with the NDK): runs the game side's calls and checks them.
// hulk_host_vsnprintf_ms shows how the host glue can take the game's MS-style `va_list` (a char* walking 8-byte
// slots) on targets whose own va_list is a struct: an AAPCS64 / SysV va_list whose register save areas are marked
// used up reads every argument from its stack pointer, in 8-byte slots, which is the MS layout.
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

extern "C" {
double game_mix(const char* types, ...);  // as a plain host prototype (AAPCS64 / SysV call: wrong under --win64cc)
#if defined(__aarch64__) || defined(__x86_64__)
double game_mix_ms(const char* types, ...) __attribute__((ms_abi)) __asm__(
#ifdef __APPLE__
    "_"
#endif
    "game_mix");  // the same function declared ms_abi: clang emits a win64cc call
#endif
double game_call_mix(void);
double game_call_mix_long(void);
int game_call_fmt(char* out);
int game_call_host_fmt(char* out);
int game_call_snprintf(char* out);

int hulk_host_vsnprintf_ms(char* buf, unsigned long long n, const char* fmt, char* ms_ap) {
#if defined(__aarch64__) && !defined(__APPLE__) && !defined(_WIN32)
    va_list ap;
    struct Aapcs { void* stack; void* gr_top; void* vr_top; int gr_offs; int vr_offs; };
    static_assert(sizeof(va_list) == sizeof(Aapcs), "AAPCS64 va_list");
    Aapcs a = {ms_ap, 0, 0, 0, 0};  // offsets >= 0: general and vector registers used up, all from `stack`
    memcpy(&ap, &a, sizeof a);
    return vsnprintf(buf, n, fmt, ap);
#elif defined(__x86_64__) && !defined(_WIN32)
    va_list ap;
    struct SysV { unsigned gp_offset, fp_offset; void* overflow; void* save; };
    static_assert(sizeof(va_list) == sizeof(SysV), "SysV va_list");
    SysV s = {48, 176, ms_ap, 0};  // 6 GPRs * 8 and + 8 XMM * 16: used up
    memcpy(&ap, &s, sizeof s);
    return vsnprintf(buf, n, fmt, ap);
#else
    return vsnprintf(buf, n, fmt, (va_list)ms_ap);  // Apple arm64 / Windows: va_list is the char* itself
#endif
}
}

static int g_fail;
static void check_d(const char* what, double got, double want) {
    printf("%-22s %s got %.6f want %.6f\n", what, got == want ? "ok  " : "FAIL", got, want);
    g_fail += got != want;
}
static void check_s(const char* what, const char* got, const char* want) {
    printf("%-22s %s got '%s' want '%s'\n", what, strcmp(got, want) ? "FAIL" : "ok  ", got, want);
    g_fail += strcmp(got, want) != 0;
}

int main(int argc, char** argv) {
    const char* only = argc > 1 ? argv[1] : "";
    char buf[256];
    double want_long = 0;
    const double v[] = {1, 0.5, 2, 0.25, 3, 0.125, 4, 0.5, 5, 0.25};
    for (double x : v) want_long = want_long * 10 + x;
    // each case alone (a broken case can crash; the script runs them one by one)
    if (!*only || !strcmp(only, "mix")) check_d("game->game mix", game_call_mix(), 1284.25);
    if (!*only || !strcmp(only, "mixlong")) check_d("game->game mix (10)", game_call_mix_long(), want_long);
    if (!*only || !strcmp(only, "fmt")) { buf[0] = 0; game_call_fmt(buf); check_s("game va_list fwd", buf, "a7b0.500cxd-2"); }
    if (!*only || !strcmp(only, "hostfmt")) { buf[0] = 0; game_call_host_fmt(buf); check_s("game->host va_list", buf, "9|1.25|y|3|2.0"); }
    if (!*only || !strcmp(only, "snprintf")) { buf[0] = 0; game_call_snprintf(buf); check_s("game->host snprintf", buf, "5/6.75/8"); }
    if (!*only || !strcmp(only, "hostcall")) check_d("host->game mix", game_mix("idid", 1, 2.5, 3, 4.25), 1284.25);
#if defined(__aarch64__) || defined(__x86_64__)
    if (!*only || !strcmp(only, "hostcall_ms")) check_d("host->game mix ms_abi", game_mix_ms("idid", 1, 2.5, 3, 4.25), 1284.25);
#endif
    printf("%s\n", g_fail ? "FAIL" : "PASS");
    return g_fail ? 1 : 0;
}
