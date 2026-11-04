// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0021f800 @ 0x0021f800
#include "compat/ptr.h"
struct LogContext {
    const char* name;
    char padding[12];
    const char* message;
};

extern "C" const char * __cdecl FUN_002160c0(void *, const char *, char *);
void __cdecl FUN_00216320(const char*, const char*, ...);
void __cdecl FUN_002152b0(const char*, int);

// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(LogContext* context, const char* format, ...)
{
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, format);
    const char* text = FUN_002160c0((void *)(const char *)(context->name), format, va);
#else
    const char* text = FUN_002160c0((void *)(const char *)(context->name), format, (char *)(void *)(&format + 1));
#endif
    FUN_00216320(context->name, "%s: %s", context->message, text);
    FUN_002152b0(context->name, 3);
}