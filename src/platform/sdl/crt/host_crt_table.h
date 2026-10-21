// The host C runtime tables of the native image (host_crt.h says how tools/native_link.py reads them).
// Data for tools/native_link.py only: never expanded by the compiler.
#ifndef HULK_PLATFORM_SDL_CRT_HOST_CRT_TABLE_H
#define HULK_PLATFORM_SDL_CRT_HOST_CRT_TABLE_H

// I(dll, name, stdcall argument bytes or -1, "export if not the name"): the import is `hulk_host_<name>`.
#define HULK_HOST_IMPORTS(I) \
    I(msvcrt, malloc, -1, "") \
    I(msvcrt, calloc, -1, "") \
    I(msvcrt, realloc, -1, "") \
    I(msvcrt, free, -1, "") \
    I(msvcrt, _msize, -1, "") \
    I(msvcrt, memset, -1, "") \
    I(msvcrt, memcpy, -1, "") \
    I(msvcrt, memmove, -1, "") \
    I(msvcrt, memcmp, -1, "") \
    I(msvcrt, memchr, -1, "") \
    I(msvcrt, strlen, -1, "") \
    I(msvcrt, wcslen, -1, "") \
    I(msvcrt, strcmp, -1, "") \
    I(msvcrt, strncmp, -1, "") \
    I(msvcrt, strcpy, -1, "") \
    I(msvcrt, strncpy, -1, "") \
    I(msvcrt, strcat, -1, "") \
    I(msvcrt, strncat, -1, "") \
    I(msvcrt, strchr, -1, "") \
    I(msvcrt, strrchr, -1, "") \
    I(msvcrt, strstr, -1, "") \
    I(msvcrt, strcspn, -1, "") \
    I(msvcrt, strpbrk, -1, "") \
    I(msvcrt, strtok, -1, "") \
    I(msvcrt, strerror, -1, "") \
    I(msvcrt, _stricmp, -1, "") \
    I(msvcrt, _strupr, -1, "") \
    I(msvcrt, toupper, -1, "") \
    I(msvcrt, tolower, -1, "") \
    I(msvcrt, isalpha, -1, "") \
    I(msvcrt, isupper, -1, "") \
    I(msvcrt, islower, -1, "") \
    I(msvcrt, isdigit, -1, "") \
    I(msvcrt, isxdigit, -1, "") \
    I(msvcrt, isspace, -1, "") \
    I(msvcrt, ispunct, -1, "") \
    I(msvcrt, isalnum, -1, "") \
    I(msvcrt, iscntrl, -1, "") \
    I(msvcrt, atoi, -1, "") \
    I(msvcrt, atol, -1, "") \
    I(msvcrt, atof, -1, "") \
    I(msvcrt, strtod, -1, "") \
    I(msvcrt, sprintf, -1, "") \
    I(msvcrt, _snprintf, -1, "") \
    I(msvcrt, _vsnprintf, -1, "") \
    I(msvcrt, vsprintf, -1, "") \
    I(msvcrt, sscanf, -1, "") \
    I(msvcrt, printf, -1, "") \
    I(msvcrt, puts, -1, "") \
    I(msvcrt, fopen, -1, "") \
    I(msvcrt, fclose, -1, "") \
    I(msvcrt, fread, -1, "") \
    I(msvcrt, fwrite, -1, "") \
    I(msvcrt, fseek, -1, "") \
    I(msvcrt, ftell, -1, "") \
    I(msvcrt, fflush, -1, "") \
    I(msvcrt, fputs, -1, "") \
    I(msvcrt, fgets, -1, "") \
    I(msvcrt, getc, -1, "") \
    I(msvcrt, ungetc, -1, "") \
    I(msvcrt, vfprintf, -1, "") \
    I(msvcrt, __iob_func, -1, "") \
    I(msvcrt, _fcloseall, -1, "") \
    I(msvcrt, getenv, -1, "") \
    I(msvcrt, exit, -1, "") \
    I(msvcrt, _exit, -1, "") \
    I(msvcrt, _errno, -1, "") \
    I(msvcrt, qsort, -1, "") \
    I(msvcrt, bsearch, -1, "") \
    I(msvcrt, rand, -1, "") \
    I(msvcrt, srand, -1, "") \
    I(msvcrt, sqrt, -1, "") \
    I(msvcrt, sin, -1, "") \
    I(msvcrt, cos, -1, "") \
    I(msvcrt, tan, -1, "") \
    I(msvcrt, asin, -1, "") \
    I(msvcrt, acos, -1, "") \
    I(msvcrt, atan, -1, "") \
    I(msvcrt, atan2, -1, "") \
    I(msvcrt, exp, -1, "") \
    I(msvcrt, log, -1, "") \
    I(msvcrt, log10, -1, "") \
    I(msvcrt, pow, -1, "") \
    I(msvcrt, fmod, -1, "") \
    I(msvcrt, floor, -1, "") \
    I(msvcrt, ceil, -1, "") \
    I(msvcrt, frexp, -1, "") \
    I(msvcrt, ldexp, -1, "") \
    I(msvcrt, _isnan, -1, "") \
    I(msvcrt, _CIpow, -1, "") \
    I(msvcrt, _CIfmod, -1, "") \
    I(msvcrt, _CIexp, -1, "") \
    I(msvcrt, _CIacos, -1, "") \
    I(msvcrt, _CIasin, -1, "") \
    I(msvcrt, _ftol, -1, "") \
    I(msvcrt, _setjmp3, -1, "") \
    I(msvcrt, longjmp, -1, "") \
    I(msvcrt, __CxxFrameHandler3, -1, "") \
    I(msvcrt, _CxxThrowException, 8, "") \
    I(msvcrt, __RTDynamicCast, -1, "") \
    I(msvcrt, __RTtypeid, -1, "") \
    I(msvcrt, _purecall, -1, "") \
    I(msvcrt, terminate, -1, "?terminate@@YAXXZ") \
    I(msvcrt, type_info_eq, -1, "??8type_info@@QBEHABV0@@Z") \
    I(msvcrt, type_info_name, -1, "?name@type_info@@QBEPBDXZ") \
    I(ntdll, _allmul, -1, "") \
    I(ntdll, _alldiv, -1, "") \
    I(ntdll, _allrem, -1, "") \
    I(ntdll, _alldvrm, -1, "") \
    I(ntdll, _allshl, -1, "") \
    I(ntdll, _allshr, -1, "") \
    I(ntdll, _aulldiv, -1, "") \
    I(ntdll, _aullrem, -1, "") \
    I(ntdll, _aulldvrm, -1, "") \
    I(ntdll, _aullshr, -1, "") \
    I(ntdll, _chkstk, -1, "") \
    I(kernel32, SetUnhandledExceptionFilter, 4, "") \
    I(kernel32, ExitProcess, 4, "") \
    I(kernel32, VirtualAlloc, 16, "") \
    I(kernel32, VirtualQuery, 12, "") \
    I(kernel32, VirtualAllocEx, 20, "") \
    I(kernel32, CreateProcessA, 40, "") \
    I(kernel32, ResumeThread, 4, "") \
    I(kernel32, WaitForSingleObject, 8, "") \
    I(kernel32, GetExitCodeProcess, 8, "") \
    I(kernel32, GetModuleFileNameA, 12, "") \
    I(kernel32, GetCommandLineA, 0, "") \
    I(kernel32, SetEnvironmentVariableA, 8, "") \
    I(kernel32, TerminateProcess, 8, "") \
    I(kernel32, QueryPerformanceCounter, 4, "") \
    I(kernel32, QueryPerformanceFrequency, 4, "") \
    I(kernel32, Sleep, 4, "") \
    I(kernel32, GetCurrentThreadId, 0, "") \
    I(kernel32, GetLocalTime, 4, "") \
    I(kernel32, CreateThread, 24, "") \
    I(kernel32, ExitThread, 4, "") \
    I(kernel32, OpenThread, 12, "") \
    I(kernel32, SuspendThread, 4, "") \
    I(kernel32, GetThreadContext, 8, "") \
    I(kernel32, SetThreadPriority, 8, "") \
    I(kernel32, CreateSemaphoreA, 16, "") \
    I(kernel32, ReleaseSemaphore, 12, "") \
    I(kernel32, ConvertThreadToFiber, 4, "") \
    I(kernel32, CreateFiber, 12, "") \
    I(kernel32, SwitchToFiber, 4, "") \
    I(kernel32, DeleteFiber, 4, "") \
    I(kernel32, InitializeCriticalSection, 4, "") \
    I(kernel32, EnterCriticalSection, 4, "") \
    I(kernel32, LeaveCriticalSection, 4, "") \
    I(kernel32, CreateFileA, 28, "") \
    I(kernel32, ReadFile, 20, "") \
    I(kernel32, WriteFile, 20, "") \
    I(kernel32, SetFilePointer, 16, "") \
    I(kernel32, GetFileSize, 8, "") \
    I(kernel32, SetEndOfFile, 4, "") \
    I(kernel32, CloseHandle, 4, "") \
    I(kernel32, GetDiskFreeSpaceExA, 16, "") \
    I(kernel32, GetLastError, 0, "") \
    I(kernel32, SetLastError, 4, "") \
    I(kernel32, CreateDirectoryA, 8, "") \
    I(kernel32, GetFileAttributesA, 4, "")

// C(xbe address or 0, host import or hulk_crt_ glue function, "tree names"). The address rows are the library
// functions the game calls (LIBCMT inside .text); the reason for each identification is the call sites' use.
#define HULK_HOST_CRT(C) \
    C(0x00344913, type_info_eq, "") \
    C(0x003449e4, __RTtypeid, "__RTtypeid") \
    C(0x00344e74, __RTDynamicCast, "__RTDynamicCast") \
    C(0x00344f75, sprintf, "_sprintf sprintf") \
    C(0x0034502e, hulk_crt_security_check_cookie, "__security_check_cookie") \
    C(0x0034511c, hulk_crt_atexit, "_atexit atexit") \
    C(0x003441f0, _CIacos, "_CIacos") \
    C(0x003442bc, _CIasin, "_CIasin") \
    C(0x0034476f, _isnan, "__isnan _isnan") \
    C(0x0034483c, _ftol, "_ftol") \
    C(0x003454a6, atol, "_atol") \
    C(0x003454fe, atol, "atol") \
    C(0x0034557c, floor, "__floor_default floor") \
    C(0x00345130, memmove, "_memmove memmove") \
    C(0x00345475, tolower, "tolower") \
    C(0x00345650, strncpy, "_strncpy strncpy") \
    C(0x00345774, _vsnprintf, "__vsnprintf _vsnprintf") \
    C(0x00345804, sscanf, "sscanf") \
    C(0x00345840, strncmp, "_strncmp strncmp") \
    C(0x00345880, _chkstk, "_chkstk") \
    C(0x003458c1, atof, "atof") \
    C(0x0034591d, isalpha, "_isalpha isalpha") \
    C(0x0034594b, isupper, "_isupper isupper") \
    C(0x00345974, islower, "_islower islower") \
    C(0x0034599d, isdigit, "_isdigit isdigit") \
    C(0x003459c6, isxdigit, "_isxdigit isxdigit") \
    C(0x003459f4, isspace, "_isspace isspace") \
    C(0x00345a1d, ispunct, "_ispunct ispunct") \
    C(0x00345a46, isalnum, "_isalnum isalnum") \
    C(0x00345ad0, iscntrl, "_iscntrl iscntrl") \
    C(0x00345b90, toupper, "toupper") \
    C(0x00345d81, _exit, "_exit") \
    C(0x00345db0, strchr, "_strchr strchr") \
    C(0x00345e70, strstr, "_strstr strstr") \
    C(0x00345f90, qsort, "_qsort qsort") \
    C(0x0034625f, hulk_crt_fclose, "_fclose fclose") \
    C(0x003463c7, hulk_crt_fwrite, "fwrite") \
    C(0x0034650b, hulk_crt_fread, "fread") \
    C(0x00347d7a, realloc, "") \
    C(0x003465b3, hulk_crt_fopen, "fopen") \
    C(0x003465c6, strtok, "strtok") \
    C(0x00346890, strrchr, "_strrchr strrchr") \
    C(0x003468c0, strncat, "_strncat strncat") \
    C(0x003469f5, type_info_name, "") \
    C(0x00346fc5, _stricmp, "__stricmp _stricmp") \
    C(0x00347010, _aulldiv, "_aulldiv") \
    C(0x003471a3, _fcloseall, "_fcloseall") \
    C(0x003471d4, longjmp, "_longjmp longjmp") \
    C(0x00347250, _setjmp3, "__setjmp3 _setjmp3") \
    C(0x003472cb, strtod, "strtod") \
    C(0x00347380, strcspn, "_strcspn strcspn") \
    C(0x003473c6, strcmp, "strcmp") \
    C(0x0034773f, srand, "_srand srand") \
    C(0x0034774c, rand, "_rand rand") \
    C(0x00347792, hulk_crt_fprintf, "_fwprintf fprintf") \
    C(0x003479aa, hulk_crt_malloc, "") \
    C(0x003479bc, free, "free") \
    C(0x003481ba, ceil, "") \
    C(0x00347a14, bsearch, "_bsearch bsearch") \
    C(0x00347aa0, calloc, "calloc") \
    C(0x00347b53, strerror, "strerror") \
    C(0x00347ba4, _errno, "_errno") \
    C(0x00347c95, hulk_crt_ungetc, "_ungetc ungetc") \
    C(0x00347d2a, hulk_crt_getc, "_getc getc") \
    C(0x00347e67, hulk_crt_fgets, "_fgets fgets") \
    C(0x00347eed, puts, "puts") \
    C(0x00347f64, frexp, "frexp") \
    C(0x00348010, ldexp, "ldexp") \
    C(0x00348290, memchr, "_memchr memchr") \
    C(0x00348340, strpbrk, "_strpbrk strpbrk") \
    C(0x00348380, _strupr, "_strupr") \
    C(0x00346672, _CIpow, "_CIpow") \
    C(0x0034777a, _CIfmod, "_CIfmod") \
    C(0x00356734, sprintf, "") \
    C(0, memcpy, "memcpy") \
    C(0, memset, "memset") \
    C(0, memcmp, "memcmp") \
    C(0, wcslen, "wcslen") \
    C(0, strlen, "strlen") \
    C(0, strcpy, "strcpy") \
    C(0, strcat, "strcat") \
    C(0, hulk_crt_malloc, "malloc") \
    C(0, sqrt, "sqrt") \
    C(0, hulk_crt_sin, "sin") \
    C(0, hulk_crt_cos, "cos") \
    C(0, hulk_crt_tan, "tan") \
    C(0, asin, "asin") \
    C(0, acos, "acos") \
    C(0, hulk_crt_atan, "atan") \
    C(0, hulk_crt_atan2, "atan2") \
    C(0, hulk_crt_exp, "exp") \
    C(0, log, "log") \
    C(0, log10, "log10") \
    C(0, pow, "pow") \
    C(0, fmod, "fmod") \
    C(0, ceil, "ceil __ceil_default") \
    C(0, _allmul, "_allmul") \
    C(0, _alldiv, "_alldiv") \
    C(0, _allrem, "_allrem") \
    C(0, _alldvrm, "_alldvrm") \
    C(0, _allshl, "_allshl") \
    C(0, _allshr, "_allshr") \
    C(0, _aullrem, "_aullrem") \
    C(0, _aulldvrm, "_aulldvrm") \
    C(0, _aullshr, "_aullshr") \
    C(0, __CxxFrameHandler3, "__CxxFrameHandler3") \
    C(0, _CxxThrowException, "_CxxThrowException") \
    C(0, _purecall, "_purecall") \
    C(0, terminate, "terminate")

// D(xbe address, our symbol, bytes): library data the game reads or writes by address, as our own definitions.
#define HULK_HOST_DATA(D) \
    D(0x004d9968, _hulk_crt_security_cookie, 4) \
    D(0x004d99f0, _hulk_crt_iob_proxy, 96) \
    D(0x00439de8, ??_7type_info@@6B@, 4)

#endif
