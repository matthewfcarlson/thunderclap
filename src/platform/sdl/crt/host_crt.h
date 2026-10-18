// The host C runtime of the native image (docs/native-build.md "Start-up").
//
// The first native image (i686-pc-windows-msvc, clang-cl + lld-link) runs on Windows or under Wine. It links the
// C runtime every Windows has, msvcrt.dll (plus four 64-bit arithmetic helpers from ntdll.dll and a few kernel32
// functions for the start-up code), through import libraries that tools/native_link.py builds with llvm-dlltool
// from the HULK_HOST_IMPORTS table below: no SDK, sysroot or MinGW is needed, and no Microsoft code is linked in.
//
// Every host function is imported under a prefixed name, `hulk_host_<name>`, so a host export can never take the
// place of one of the tree's own symbols (the tree calls the game's operator new `malloc` in one source and the
// game's free thunk `free` in another: those stay bound to the game's code by address). tools/native_link.py
// aliases the tree's references to these names:
//
//   * by XBE address: every symbol the binding map binds to a library address in HULK_HOST_CRT gets that row's
//     host function (or our own glue function, HULK_CRT_GLUE);
//   * by name: an undefined symbol with no binding whose plain name is one of a row's tree names (`_floor`,
//     `__floor_default`, `memcpy` from clang's own lowering of a struct copy, ...).
//
// Which standard function each library address is was decided from the game's call sites (arguments, use of the
// result) and the names the sources and tools/platform_map.py give it, never from the library's code; the notes
// say why where the name the tools carry is wrong (0x003465c6 is strtok, not _nh_malloc).
#ifndef HULK_PLATFORM_SDL_CRT_HOST_CRT_H
#define HULK_PLATFORM_SDL_CRT_HOST_CRT_H

typedef unsigned int hulk_u32;

#if defined(_M_IX86) || defined(__i386__)
#define HULK_HOST_CDECL __cdecl
#define HULK_HOST_STDCALL __stdcall
#else
#define HULK_HOST_CDECL
#define HULK_HOST_STDCALL
#endif

// ---------------------------------------------------------------------------------------------------------------
// The tables (read by tools/native_link.py; never expanded by the compiler).
//
// HULK_HOST_IMPORTS: I(dll, export, stdcall argument bytes or -1 for cdecl / not decorated): every host function
// the image imports. The import library defines `_hulk_host_<export>` (`_hulk_host_<export>@N` for stdcall).
//
// HULK_HOST_CRT: C(xbe address or 0, host export or glue name, "tree names"): what the tree's references to a
// library address or a CRT name become. A name starting with `hulk_crt_` is our own function (crt_glue.cpp), any
// other a host import of HULK_HOST_IMPORTS. Tree names are plain C identifiers as the sources and clang spell
// them (`_sprintf` is the source's name for sprintf, symbol `__sprintf`).
#include "host_crt_table.h"

extern "C" {
// ---------------------------------------------------------------------------------------------------------------
// Host functions our own code calls (declared here, not through the host's headers: the native build has none).
typedef struct hulk_host_file hulk_host_file;
void* HULK_HOST_CDECL hulk_host_malloc(hulk_u32 size);
void* HULK_HOST_CDECL hulk_host_calloc(hulk_u32 n, hulk_u32 size);
void* HULK_HOST_CDECL hulk_host_realloc(void* p, hulk_u32 size);
void HULK_HOST_CDECL hulk_host_free(void* p);
hulk_u32 HULK_HOST_CDECL hulk_host__msize(void* p);
void* HULK_HOST_CDECL hulk_host_memset(void* p, int c, hulk_u32 n);
void* HULK_HOST_CDECL hulk_host_memcpy(void* d, const void* s, hulk_u32 n);
hulk_u32 HULK_HOST_CDECL hulk_host_strlen(const char* s);
int HULK_HOST_CDECL hulk_host_strcmp(const char* a, const char* b);
char* HULK_HOST_CDECL hulk_host_getenv(const char* name);
int HULK_HOST_CDECL hulk_host__snprintf(char* buf, hulk_u32 n, const char* fmt, ...);
int HULK_HOST_CDECL hulk_host__vsnprintf(char* buf, hulk_u32 n, const char* fmt, char* args);
hulk_host_file* HULK_HOST_CDECL hulk_host_fopen(const char* path, const char* mode);
int HULK_HOST_CDECL hulk_host_fclose(hulk_host_file* f);
hulk_u32 HULK_HOST_CDECL hulk_host_fread(void* p, hulk_u32 size, hulk_u32 n, hulk_host_file* f);
hulk_u32 HULK_HOST_CDECL hulk_host_fwrite(const void* p, hulk_u32 size, hulk_u32 n, hulk_host_file* f);
int HULK_HOST_CDECL hulk_host_fseek(hulk_host_file* f, long off, int whence);
long HULK_HOST_CDECL hulk_host_ftell(hulk_host_file* f);
int HULK_HOST_CDECL hulk_host_fflush(hulk_host_file* f);
int HULK_HOST_CDECL hulk_host_fputs(const char* s, hulk_host_file* f);
char* HULK_HOST_CDECL hulk_host_fgets(char* s, int n, hulk_host_file* f);
int HULK_HOST_CDECL hulk_host_getc(hulk_host_file* f);
int HULK_HOST_CDECL hulk_host_ungetc(int c, hulk_host_file* f);
int HULK_HOST_CDECL hulk_host_vfprintf(hulk_host_file* f, const char* fmt, char* args);
hulk_host_file* HULK_HOST_CDECL hulk_host___iob_func(void);  // &stdin; stdout and stderr follow (32 bytes each)
void HULK_HOST_CDECL hulk_host_exit(int code);

// kernel32 (start-up, crash report, time, threads: Windows / Wine only, until the SDL3 backends)
void* HULK_HOST_STDCALL hulk_host_SetUnhandledExceptionFilter(void* filter);
void HULK_HOST_STDCALL hulk_host_ExitProcess(hulk_u32 code);
void* HULK_HOST_STDCALL hulk_host_VirtualAlloc(void* addr, hulk_u32 size, hulk_u32 type, hulk_u32 protect);
hulk_u32 HULK_HOST_STDCALL hulk_host_VirtualQuery(const void* addr, void* info, hulk_u32 size);
void* HULK_HOST_STDCALL hulk_host_VirtualAllocEx(void* process, void* addr, hulk_u32 size, hulk_u32 type, hulk_u32 prot);
int HULK_HOST_STDCALL hulk_host_CreateProcessA(const char* app, char* cmd, void* pa, void* ta, int inherit, hulk_u32 flags,
                                               void* env, const char* dir, void* startup, void* info);
hulk_u32 HULK_HOST_STDCALL hulk_host_ResumeThread(void* thread);
hulk_u32 HULK_HOST_STDCALL hulk_host_WaitForSingleObject(void* h, hulk_u32 ms);
int HULK_HOST_STDCALL hulk_host_GetExitCodeProcess(void* process, hulk_u32* code);
hulk_u32 HULK_HOST_STDCALL hulk_host_GetModuleFileNameA(void* module, char* buf, hulk_u32 size);
char* HULK_HOST_STDCALL hulk_host_GetCommandLineA(void);
int HULK_HOST_STDCALL hulk_host_SetEnvironmentVariableA(const char* name, const char* value);
int HULK_HOST_STDCALL hulk_host_TerminateProcess(void* process, hulk_u32 code);
int HULK_HOST_STDCALL hulk_host_QueryPerformanceCounter(void* count);
int HULK_HOST_STDCALL hulk_host_QueryPerformanceFrequency(void* freq);
void HULK_HOST_STDCALL hulk_host_Sleep(hulk_u32 ms);
hulk_u32 HULK_HOST_STDCALL hulk_host_GetCurrentThreadId(void);
void HULK_HOST_STDCALL hulk_host_GetLocalTime(void* system_time);
void* HULK_HOST_STDCALL hulk_host_CreateThread(void* sa, hulk_u32 stack, void* start, void* param, hulk_u32 flags,
                                              hulk_u32* tid);
void HULK_HOST_STDCALL hulk_host_ExitThread(hulk_u32 code);
int HULK_HOST_STDCALL hulk_host_SetThreadPriority(void* thread, int priority);
void* HULK_HOST_STDCALL hulk_host_CreateSemaphoreA(void* sa, int initial, int maximum, const char* name);
int HULK_HOST_STDCALL hulk_host_ReleaseSemaphore(void* sem, int count, int* previous);
void* HULK_HOST_STDCALL hulk_host_ConvertThreadToFiber(void* param);
void* HULK_HOST_STDCALL hulk_host_CreateFiber(hulk_u32 stack, void* start, void* param);
void HULK_HOST_STDCALL hulk_host_SwitchToFiber(void* fiber);
void HULK_HOST_STDCALL hulk_host_DeleteFiber(void* fiber);
void HULK_HOST_STDCALL hulk_host_InitializeCriticalSection(void* cs);
void HULK_HOST_STDCALL hulk_host_EnterCriticalSection(void* cs);
void HULK_HOST_STDCALL hulk_host_LeaveCriticalSection(void* cs);
void* HULK_HOST_STDCALL hulk_host_CreateFileA(const char* path, hulk_u32 access, hulk_u32 share, void* sa,
                                             hulk_u32 disposition, hulk_u32 flags, void* templ);
int HULK_HOST_STDCALL hulk_host_ReadFile(void* h, void* buf, hulk_u32 n, hulk_u32* done, void* overlapped);
int HULK_HOST_STDCALL hulk_host_WriteFile(void* h, const void* buf, hulk_u32 n, hulk_u32* done, void* overlapped);
hulk_u32 HULK_HOST_STDCALL hulk_host_SetFilePointer(void* h, int lo, int* hi, hulk_u32 method);
hulk_u32 HULK_HOST_STDCALL hulk_host_GetFileSize(void* h, hulk_u32* hi);
int HULK_HOST_STDCALL hulk_host_SetEndOfFile(void* h);
int HULK_HOST_STDCALL hulk_host_CloseHandle(void* h);
int HULK_HOST_STDCALL hulk_host_GetDiskFreeSpaceExA(const char* path, void* avail, void* total, void* free_);
hulk_u32 HULK_HOST_STDCALL hulk_host_GetLastError(void);
void HULK_HOST_STDCALL hulk_host_SetLastError(hulk_u32 code);
int HULK_HOST_STDCALL hulk_host_CreateDirectoryA(const char* path, void* sa);
hulk_u32 HULK_HOST_STDCALL hulk_host_GetFileAttributesA(const char* path);

// ---------------------------------------------------------------------------------------------------------------
// Our own runtime pieces (crt_glue.cpp) that other platform files use.
// The game's path for a file (`D:\data\x.rcf`, `d:\x`, `T:\...`) -> a host path under HULK_DATA_DIR (the extracted
// game files) or HULK_SAVE_DIR; returns buf, or 0 if the path is not one we map.
char* hulk_crt_host_path(const char* game_path, char* buf, hulk_u32 size);
}

#endif
