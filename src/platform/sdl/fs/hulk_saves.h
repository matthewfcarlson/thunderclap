// Save games on the native file backend (docs/native-files-saves.md): the Xbox's save-game folders and the
// signature the game stamps on its own save blocks.
//
// Layout (the public description of the Xbox hard disk): a save game is a directory under the drive's root
// (U:\ = UDATA\<title id>); it holds SaveMeta.xbx (UTF-16, `Name=<save name>`), the game's own files, and the
// drive root holds TitleMeta.xbx (`TitleName=<title>`). The directory name is ours: 12 hex digits of a 64-bit
// FNV-1a hash of the save name, probed forward on a clash with a different name.
//
// Signatures: HMAC-SHA1 (20 bytes) under a key derived from the title id. The Xbox's key is a secret of the
// console's firmware and the title's certificate, so a save written on a console does not verify here and a save
// written here does not verify there; verification is consistent with our writer, which is all the game asks.
#ifndef HULK_PLATFORM_SDL_SAVES_H
#define HULK_PLATFORM_SDL_SAVES_H

#include "hulk_fs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HULK_SAVE_NAME_CHARS 128         // the longest save name, with its terminator

typedef struct HulkSaveFind {
    HulkFindEntry directory;             // the save directory's entry (name = its folder name)
    char path[260];                      // `<drive>:\<folder>\`
    unsigned short name[HULK_SAVE_NAME_CHARS];     // the save's name (UTF-16)
} HulkSaveFind;

// `root` is a drive root such as "U:\" (or "U:"); `name` is UTF-16, NUL-terminated.
// Dispositions are CreateFile's: CREATE_NEW fails with ALREADY_EXISTS, OPEN_EXISTING with PATH_NOT_FOUND when the
// save is absent, CREATE_ALWAYS empties an existing one, OPEN_ALWAYS creates when absent. `path` receives the
// directory with a trailing backslash.
unsigned hulk_save_create(const char* root, const unsigned short* name, unsigned disposition, char* path,
                          unsigned path_size);
unsigned hulk_save_delete(const char* root, const unsigned short* name);
unsigned hulk_save_find_first(const char* root, HulkSaveFind* out, HulkFsHandle* h);   // NO_MORE_FILES: none
unsigned hulk_save_find_next(HulkFsHandle h, HulkSaveFind* out);

// Signatures
#define HULK_SIGNATURE_BYTES 20
unsigned hulk_sig_begin(unsigned flags, HulkFsHandle* h);
unsigned hulk_sig_update(HulkFsHandle h, const void* data, unsigned size);
unsigned hulk_sig_end(HulkFsHandle h, unsigned char out[HULK_SIGNATURE_BYTES]);   // closes the handle

// SHA-1 / HMAC-SHA1 (our own implementation of the published algorithms; exposed for the tests)
typedef struct HulkSha1 {
    unsigned h[5];
    unsigned long long length;
    unsigned char block[64];
    unsigned used;
} HulkSha1;
void hulk_sha1_init(HulkSha1* c);
void hulk_sha1_update(HulkSha1* c, const void* data, unsigned size);
void hulk_sha1_final(HulkSha1* c, unsigned char out[20]);
void hulk_hmac_sha1(const unsigned char* key, unsigned key_size, const void* data, unsigned size,
                    unsigned char out[20]);

#ifdef __cplusplus
}
#endif

#endif
