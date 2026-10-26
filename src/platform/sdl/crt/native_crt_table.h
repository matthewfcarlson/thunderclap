// The C runtime of the native builds (docs/native-mac.md "Host side"): what each row of host_crt_table.h's
// HULK_HOST_CRT (the library functions the game calls by XBE address or by name) becomes on macOS / Linux, plus the
// rest of include/compat/crt.h. Data for the native link only (tools/native_mac.py crt reads it; never expanded by
// the compiler). The Wine build keeps host_crt_table.h, which this file does not change.
//
// N(xbe address or 0, kind, target, "tree names"):
//   libc   the host's C library function of that name: same arguments at the same widths, same results (the
//          game side is LLP64: `long` is 4 bytes; size_t arguments are 64-bit there too, compat/crt.h)
//   glue   our function (src/platform/sdl/host/crt_posix.cpp): MS semantics the host's lacks (_snprintf's -1 on
//          truncation, rand's sequence, 16-bit wchar_t, per-thread strtok, a 64-byte jmp_buf), a `long` argument the
//          game passes as 32 bits, the game's paths and stdio objects, the zeroing malloc
//   math   our function forwarding to soft-intrinsics' routines (src/platform/sdl/crt/softx87.h: what x87 hardware
//          returns) where it provides one, to the host's libm otherwise (sqrt, the float variants: exact or not
//          inlined as x87 instructions by MSVC 7.1)
//   abi    the MS C++ ABI's run-time support (docs/native-mac.md section 7): RTTI (dynamic_cast, typeid, type_info's
//          members) and the exception personality, in src/platform/sdl/host/rtti_msabi.cpp
//   na     an x86 compiler helper with a register convention (64-bit compilers never call it; a source naming one
//          by its symbol needs rewriting)
#ifndef HULK_PLATFORM_SDL_CRT_NATIVE_CRT_TABLE_H
#define HULK_PLATFORM_SDL_CRT_NATIVE_CRT_TABLE_H

#define HULK_NATIVE_CRT(N) \
    N(0x00344913, abi, hulk_ncrt_type_info_eq, "") \
    N(0x003449e4, abi, hulk_ncrt_RTtypeid, "__RTtypeid") \
    N(0x00344e74, abi, hulk_ncrt_RTDynamicCast, "__RTDynamicCast") \
    N(0x00344f75, libc, sprintf, "_sprintf sprintf") \
    N(0x0034502e, glue, hulk_ncrt_security_check_cookie, "__security_check_cookie") \
    N(0x0034511c, glue, hulk_ncrt_atexit, "_atexit atexit") \
    N(0x003441f0, math, hulk_ncrt_acos, "_CIacos") \
    N(0x003442bc, math, hulk_ncrt_asin, "_CIasin") \
    N(0x0034476f, glue, hulk_ncrt_isnan, "__isnan _isnan") \
    N(0x0034483c, glue, hulk_ncrt_ftol, "_ftol") \
    N(0x003454a6, libc, atol, "_atol") \
    N(0x003454fe, libc, atol, "atol") \
    N(0x0034557c, libc, floor, "__floor_default floor") \
    N(0x00345130, libc, memmove, "_memmove memmove") \
    N(0x00345475, libc, tolower, "tolower") \
    N(0x00345650, libc, strncpy, "_strncpy strncpy") \
    N(0x00345774, glue, hulk_ncrt_vsnprintf_ms, "__vsnprintf _vsnprintf") \
    N(0x00345804, libc, sscanf, "sscanf") \
    N(0x00345840, libc, strncmp, "_strncmp strncmp") \
    N(0x00345880, na, _chkstk, "_chkstk") \
    N(0x003458c1, libc, atof, "atof") \
    N(0x0034591d, libc, isalpha, "_isalpha isalpha") \
    N(0x0034594b, libc, isupper, "_isupper isupper") \
    N(0x00345974, libc, islower, "_islower islower") \
    N(0x0034599d, libc, isdigit, "_isdigit isdigit") \
    N(0x003459c6, libc, isxdigit, "_isxdigit isxdigit") \
    N(0x003459f4, libc, isspace, "_isspace isspace") \
    N(0x00345a1d, libc, ispunct, "_ispunct ispunct") \
    N(0x00345a46, libc, isalnum, "_isalnum isalnum") \
    N(0x00345ad0, libc, iscntrl, "_iscntrl iscntrl") \
    N(0x00345b90, libc, toupper, "toupper") \
    N(0x00345d81, libc, _exit, "_exit") \
    N(0x00345db0, libc, strchr, "_strchr strchr") \
    N(0x00345e70, libc, strstr, "_strstr strstr") \
    N(0x00345f90, libc, qsort, "_qsort qsort") \
    N(0x0034625f, glue, hulk_ncrt_fclose, "_fclose fclose") \
    N(0x003463c7, glue, hulk_ncrt_fwrite, "fwrite") \
    N(0x0034650b, glue, hulk_ncrt_fread, "fread") \
    N(0x00347d7a, libc, realloc, "") \
    N(0x003465b3, glue, hulk_ncrt_fopen, "fopen") \
    N(0x003465c6, glue, hulk_ncrt_strtok, "strtok") \
    N(0x00346890, libc, strrchr, "_strrchr strrchr") \
    N(0x003468c0, libc, strncat, "_strncat strncat") \
    N(0x003469f5, abi, hulk_ncrt_type_info_name, "") \
    N(0x00346fc5, libc, strcasecmp, "__stricmp _stricmp") \
    N(0x00347010, na, _aulldiv, "_aulldiv") \
    N(0x003471a3, glue, hulk_ncrt_fcloseall, "_fcloseall") \
    N(0x003471d4, glue, hulk_ncrt_longjmp, "_longjmp longjmp") \
    N(0x00347250, glue, hulk_ncrt_setjmp3, "__setjmp3 _setjmp3") \
    N(0x003472cb, libc, strtod, "strtod") \
    N(0x00347380, libc, strcspn, "_strcspn strcspn") \
    N(0x003473c6, libc, strcmp, "strcmp") \
    N(0x0034773f, glue, hulk_ncrt_srand, "_srand srand") \
    N(0x0034774c, glue, hulk_ncrt_rand, "_rand rand") \
    N(0x00347792, glue, hulk_ncrt_fprintf, "_fwprintf fprintf") \
    N(0x003479aa, glue, hulk_ncrt_malloc, "") \
    N(0x003479bc, libc, free, "free") \
    N(0x003481ba, libc, ceil, "") \
    N(0x00347a14, libc, bsearch, "_bsearch bsearch") \
    N(0x00347aa0, libc, calloc, "calloc") \
    N(0x00347b53, libc, strerror, "strerror") \
    N(0x00347ba4, glue, hulk_ncrt_errno, "_errno") \
    N(0x00347c95, glue, hulk_ncrt_ungetc, "_ungetc ungetc") \
    N(0x00347d2a, glue, hulk_ncrt_getc, "_getc getc") \
    N(0x00347e67, glue, hulk_ncrt_fgets, "_fgets fgets") \
    N(0x00347eed, libc, puts, "puts") \
    N(0x00347f64, libc, frexp, "frexp") \
    N(0x00348010, libc, ldexp, "ldexp") \
    N(0x00348290, libc, memchr, "_memchr memchr") \
    N(0x00348340, libc, strpbrk, "_strpbrk strpbrk") \
    N(0x00348380, glue, hulk_ncrt_strlwr, "_strlwr") \
    N(0x00346672, math, hulk_ncrt_pow, "_CIpow") \
    N(0x0034777a, math, hulk_ncrt_fmod, "_CIfmod") \
    N(0x00356734, libc, sprintf, "") \
    N(0, libc, memcpy, "memcpy") \
    N(0, libc, memset, "memset") \
    N(0, libc, memcmp, "memcmp") \
    N(0, glue, hulk_ncrt_wcslen16, "wcslen") \
    N(0, libc, strlen, "strlen") \
    N(0, libc, strcpy, "strcpy") \
    N(0, libc, strcat, "strcat") \
    N(0, glue, hulk_ncrt_malloc, "malloc") \
    N(0, math, hulk_ncrt_sqrt, "sqrt") \
    N(0, math, hulk_ncrt_sin, "sin") \
    N(0, math, hulk_ncrt_cos, "cos") \
    N(0, math, hulk_ncrt_tan, "tan") \
    N(0, math, hulk_ncrt_asin, "asin") \
    N(0, math, hulk_ncrt_acos, "acos") \
    N(0, math, hulk_ncrt_atan, "atan") \
    N(0, math, hulk_ncrt_atan2, "atan2") \
    N(0, math, hulk_ncrt_exp, "exp") \
    N(0, math, hulk_ncrt_log, "log") \
    N(0, math, hulk_ncrt_log10, "log10") \
    N(0, math, hulk_ncrt_pow, "pow") \
    N(0, math, hulk_ncrt_fmod, "fmod") \
    N(0, libc, ceil, "ceil __ceil_default") \
    N(0, na, _allmul, "_allmul") \
    N(0, na, _alldiv, "_alldiv") \
    N(0, na, _allrem, "_allrem") \
    N(0, na, _alldvrm, "_alldvrm") \
    N(0, na, _allshl, "_allshl") \
    N(0, na, _allshr, "_allshr") \
    N(0, na, _aullrem, "_aullrem") \
    N(0, na, _aulldvrm, "_aulldvrm") \
    N(0, na, _aullshr, "_aullshr") \
    N(0, abi, hulk_ncrt_CxxFrameHandler3, "__CxxFrameHandler3") \
    N(0, glue, hulk_ncrt_CxxThrowException, "_CxxThrowException") \
    N(0, glue, hulk_ncrt_purecall, "_purecall") \
    N(0, glue, hulk_ncrt_terminate, "terminate") \
    N(0, glue, hulk_ncrt_snprintf_ms, "_snprintf") \
    N(0, libc, vsprintf, "vsprintf") \
    N(0, libc, printf, "printf") \
    N(0, libc, strcasecmp, "stricmp") \
    N(0, libc, strncasecmp, "_strnicmp strnicmp") \
    N(0, libc, atoi, "atoi") \
    N(0, glue, hulk_ncrt_strtol, "strtol") \
    N(0, glue, hulk_ncrt_strtoul, "strtoul") \
    N(0, libc, abs, "abs") \
    N(0, glue, hulk_ncrt_labs, "labs") \
    N(0, libc, fabs, "fabs") \
    N(0, libc, modf, "modf") \
    N(0, libc, floor, "floor") \
    N(0, libc, ldexp, "ldexp") \
    N(0, libc, frexp, "frexp") \
    N(0, libc, realloc, "realloc") \
    N(0, libc, free, "free") \
    N(0, libc, calloc, "calloc") \
    N(0, libc, sqrtf, "sqrtf") \
    N(0, libc, fabsf, "fabsf") \
    N(0, libc, floorf, "floorf") \
    N(0, libc, ceilf, "ceilf") \
    N(0, math, hulk_ncrt_sinf, "sinf") \
    N(0, math, hulk_ncrt_cosf, "cosf") \
    N(0, math, hulk_ncrt_tanf, "tanf") \
    N(0, math, hulk_ncrt_asinf, "asinf") \
    N(0, math, hulk_ncrt_acosf, "acosf") \
    N(0, math, hulk_ncrt_atanf, "atanf") \
    N(0, math, hulk_ncrt_atan2f, "atan2f") \
    N(0, math, hulk_ncrt_expf, "expf") \
    N(0, math, hulk_ncrt_logf, "logf") \
    N(0, math, hulk_ncrt_powf, "powf") \
    N(0, math, hulk_ncrt_fmodf, "fmodf")

// Library data the game reads or writes by address (host_crt_table.h HULK_HOST_DATA), on the native builds:
// D(xbe address, our symbol, bytes)
#define HULK_NATIVE_CRT_DATA(D) \
    D(0x004d9968, hulk_ncrt_security_cookie, 4) \
    D(0x004d99f0, hulk_ncrt_iob_proxy, 96)
// (0x00439de8, type_info's vftable: abi, `??_7type_info@@6B@` in rtti_msabi.cpp)

#endif
