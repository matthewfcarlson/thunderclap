// The XDK calls of the save drive (src/platform/xbox/core/XboxSaveDrive.cpp), declared once, as the SDL shim defines
// them (src/platform/sdl/xdk/file_io.cpp, saves.cpp): pointers and HANDLEs are pointer-sized, so the native link binds
// every call. The game keeps a handle in a 32-bit word (core::File's view, the drive's slots, the block cache): the
// shim's handles are small tagged indices, and INVALID_HANDLE_VALUE truncates to 0xffffffff. (drive1, D141; the
// TU's blocks had declared each of these with their own int / unsigned spellings, which bound nothing natively.)
#ifndef HULK_DECLS_SAVE_XDK_H
#define HULK_DECLS_SAVE_XDK_H

extern "C" {
void* __stdcall FUN_002109f1(const char* path, unsigned int access, unsigned int share, void* security,
                             unsigned int disposition, unsigned int flags, void* templ);           // CreateFileA
int __stdcall FUN_0020ff8d(void* file, void* buffer, unsigned int count, unsigned int* done, void* ov);  // ReadFile
int __stdcall FUN_0021007a(void* file, const void* buffer, unsigned int count, unsigned int* done,
                           void* ov);                                                              // WriteFile
unsigned int __stdcall FUN_002101d4(void* file, unsigned int low, void* high, unsigned int method); // SetFilePointer
unsigned int __stdcall FUN_002109b6(void* file, void* high);                                       // GetFileSize
int __stdcall FUN_00210150(void* file);                                                            // SetEndOfFile
int __stdcall FUN_0020bbc2(void* handle);                                                          // CloseHandle
int __stdcall FUN_00208b9c(const char* path, void* available, void* total, void* free);           // GetDiskFreeSpaceExA
unsigned int __stdcall FUN_00209a8e(const char* path);                                             // XGetDiskSectorSizeA
unsigned int __stdcall FUN_0035618d(const char* root, const unsigned short* name, unsigned int disposition,
                                    unsigned int reserved, char* path, unsigned int size);        // XCreateSaveGame
unsigned int __stdcall FUN_003563f0(const char* root, const unsigned short* name);                // XDeleteSaveGame
void* __stdcall FUN_003564c0(const char* root, void* data);                                        // XFindFirstSaveGame
int __stdcall FUN_003565ca(void* find, void* data);                                                // XFindNextSaveGame
int __stdcall FUN_00356611(void* find);                                                            // XFindClose
void* __stdcall XCalculateSignatureBegin(unsigned int flags);
unsigned int __stdcall FUN_002120f5(void* signature, const void* data, unsigned int size);         // ...Update
unsigned int __stdcall FUN_00212143(void* signature, void* digest);                                // ...End
}
// a 32-bit handle word as the HANDLE the calls take, and back
#define HULK_SAVE_HANDLE(word) ((void*)(hulk_uintptr)(unsigned int)(word))
#define HULK_SAVE_WORD(handle) ((unsigned int)(hulk_uintptr)(handle))

#endif
