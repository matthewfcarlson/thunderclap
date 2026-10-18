// The one declaration of each C runtime function the tree calls (native build only; included by compat/native.h).
// See docs/native-build.md ("After fix 4"). The MSVC 7.1 verification build never includes this header.
//
// Sources declare their CRT callees themselves, sometimes with their own types (`extern "C" float sin(float)`,
// `void __fastcall __security_check_cookie(unsigned long)`, `void _atexit(void (*)(void))`). MSVC 7.1 accepts
// one C name declared two ways in two namespaces; clang does not. tools/gen_tree.py therefore puts every C-linkage
// declaration of a name declared here inside `#if !defined(HULK_COMPAT_CRT)`: the verification build keeps the
// source's tokens, a native build sees only these. The names are read from this file by gen_tree.py
// (crt_names(): the identifier before the first `(` of each declaration line between the markers below), so a
// function added here is guarded in the tree from the next generation on.
//
// Types are MSVC 7.1's for x86 (size_t = unsigned int, va_list = char*, wchar_t = unsigned short: the native build
// compiles with -Xclang -fno-wchar like MSVC 7.1's default /Zc:wchar_t-). Calls that passed a float to a source's
// `float sin(float)` now convert to double and back, which is what the x87 code computed anyway.
#ifndef HULK_COMPAT_CRT_H
#define HULK_COMPAT_CRT_H
#define HULK_COMPAT_CRT 1

extern "C" {
// -- crt names begin
void* __cdecl memset(void*, int, size_t);
void* __cdecl memcpy(void*, const void*, size_t);
void* __cdecl memmove(void*, const void*, size_t);
int __cdecl memcmp(const void*, const void*, size_t);
size_t __cdecl strlen(const char*);
int __cdecl strcmp(const char*, const char*);
int __cdecl strncmp(const char*, const char*, size_t);
int __cdecl _stricmp(const char*, const char*);
int __cdecl stricmp(const char*, const char*);
int __cdecl _strnicmp(const char*, const char*, size_t);
int __cdecl strnicmp(const char*, const char*, size_t);
char* __cdecl strcpy(char*, const char*);
char* __cdecl strncpy(char*, const char*, size_t);
char* __cdecl strcat(char*, const char*);
char* __cdecl strchr(const char*, int);
char* __cdecl strrchr(const char*, int);
char* __cdecl strstr(const char*, const char*);
char* __cdecl strtok(char*, const char*);
size_t __cdecl wcslen(const unsigned short*);
int __cdecl sprintf(char*, const char*, ...);
int __cdecl _snprintf(char*, size_t, const char*, ...);
int __cdecl vsprintf(char*, const char*, char*);
int __cdecl sscanf(const char*, const char*, ...);
int __cdecl printf(const char*, ...);
int __cdecl atoi(const char*);
long __cdecl atol(const char*);
double __cdecl atof(const char*);
long __cdecl strtol(const char*, char**, int);
unsigned long __cdecl strtoul(const char*, char**, int);
double __cdecl strtod(const char*, char**);
int __cdecl toupper(int);
int __cdecl tolower(int);
int __cdecl isspace(int);
int __cdecl isdigit(int);
int __cdecl isalpha(int);
void* __cdecl malloc(size_t);
void* __cdecl calloc(size_t, size_t);
void* __cdecl realloc(void*, size_t);
void __cdecl free(void*);
int __cdecl abs(int);
long __cdecl labs(long);
int __cdecl rand(void);
void __cdecl srand(unsigned int);
void __cdecl qsort(void*, size_t, size_t, int(__cdecl*)(const void*, const void*));
void* __cdecl bsearch(const void*, const void*, size_t, size_t, int(__cdecl*)(const void*, const void*));
int __cdecl atexit(void(__cdecl*)(void));
int __cdecl _atexit(void(__cdecl*)(void));
void __fastcall __security_check_cookie(unsigned int);
double __cdecl sqrt(double);
double __cdecl fabs(double);
double __cdecl sin(double);
double __cdecl cos(double);
double __cdecl tan(double);
double __cdecl asin(double);
double __cdecl acos(double);
double __cdecl atan(double);
double __cdecl atan2(double, double);
double __cdecl exp(double);
double __cdecl log(double);
double __cdecl log10(double);
double __cdecl pow(double, double);
double __cdecl floor(double);
double __cdecl ceil(double);
double __cdecl fmod(double, double);
double __cdecl ldexp(double, int);
double __cdecl frexp(double, int*);
double __cdecl modf(double, double*);
float __cdecl sqrtf(float);
float __cdecl fabsf(float);
float __cdecl sinf(float);
float __cdecl cosf(float);
float __cdecl tanf(float);
float __cdecl asinf(float);
float __cdecl acosf(float);
float __cdecl atanf(float);
float __cdecl atan2f(float, float);
float __cdecl expf(float);
float __cdecl logf(float);
float __cdecl powf(float, float);
float __cdecl floorf(float);
float __cdecl ceilf(float);
float __cdecl fmodf(float, float);
// -- crt names end
}

#endif
