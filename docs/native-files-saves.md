# Native files and saves (fs1)

The native image ([native-build.md](native-build.md)) replaces the XDK's file and save calls with our own on SDL3
(`SDL_IOStream`, SDL_filesystem, SDL_Storage). Clean-room as the rest of the platform layer
([platform-boundary.md](platform-boundary.md) rules): shapes come from the game's verified call sites; the Xbox
on-disk structure follows public descriptions; no Microsoft code.

```sh
PY=build/venv/bin/python
$PY tools/native_fs.py test        # host: typed API (tests/native_fs/fs_test.cpp)
$PY tools/native_fs.py wine-test   # i686 under Wine: the same checks through the hulk_xdk_* stand-ins
$PY tools/native_fs.py backends    # build/third_party/out/fs1/win32/hulk_fs.lib + shim objects for the link
```

Last run: host 135 checks, Wine 138 checks (the extra three exercise a host handle passing through CloseHandle), 0 failed.

## Layers

`src/platform/sdl/fs/hulk_fs.{h,cpp}` and `hulk_saves.{h,cpp}` are typed (Win32 error codes, 32-bit handles, 64-bit
offsets, no C library: SDL functions only, so the i686 image keeps its names clear of the host runtime).
`src/platform/sdl/xdk/file_io.cpp` and `saves.cpp` translate the game's 32-bit arguments; `-DHULK_NATIVE_SDL=1`
selects them, without it the previous host-kernel32 stand-ins and skeleton stay.

## Drives and paths

| game | host (HULK_* env, or `HulkFsConfig`) |
|---|---|
| `D:\` and paths with a leading backslash or no drive | the extracted game files (`HULK_DATA_DIR`), read-only (writes: 5) |
| `T:\` | `HULK_TDATA_DIR`, else `<root>/TDATA/<title id>` |
| `U:\` (saves) | `HULK_UDATA_DIR`, else `<root>/UDATA/<title id>` |
| `Z:\` | `HULK_CACHE_DIR`, else `<root>/cache` |
| `C: E: F: X: Y:` | `<root>/<letter>` |

`<root>` is `HULK_SAVE_DIR`, else `SDL_GetPrefPath("Thunderclap", "HulkUD")`; title id `0x56550039` (the game's
certificate). (Previously T:/U:/Z: shared one flat directory; this is the Xbox's layout.) Separators `\` and `/`,
`.` and `..` (never above the root), `\??\` prefix. Every component is matched against the real directory
case-insensitively (ASCII folding; an index per directory, sorted, cached; exact-case spelling wins where a case-
sensitive filesystem holds two); a name that does not exist keeps the case the game gave. Writable drives re-list
once on a miss. The tests resolve through the index on case-insensitive APFS too (the stored case comes back).

## Files

CreateFileA dispositions 1-5, read/write/seek (64-bit)/size/SetEndOfFile (grow with zeros, shrink by copy and
rename: SDL has no truncate), writes flushed so other handles see them, stdio read/write switching handled. Parents
of a created file are made on the writable drives. What the verified callers use: CreateFileA with
`FILE_ATTRIBUTE_NORMAL`, synchronous ReadFile/WriteFile with a null OVERLAPPED, SetFilePointer(h, off, 0, BEGIN),
GetFileSize(h, 0), SetEndOfFile, CloseHandle; the game's own async layer (FileReadRequest on the drive thread and
fibers) sits above these. An OVERLAPPED is honoured anyway (offset from it, completes synchronously, Internal /
InternalHigh filled, hEvent not signalled). `CloseHandle` also receives the game's thread/semaphore handles: not ours
-> the host's CloseHandle. Handles are `0x46gg0nnn` (tag, generation, slot): never a host handle.
Free space: the disc 1 GB of 8 GB (fixed), writable drives the real remaining space capped at 8 GB (`HulkFsConfig.free_bytes`
overrides, for tests); sector size 2048 for D: (the game's anti-piracy check requires it), 512 elsewhere.

Library entry points the game reaches by address, all through `file_io.cpp`: 0x0021257d (misnamed XapiOpenDirectory)
is **file destroy** (`core::XboxDrive::vfunc_17`, DriveFileDestroyRequest); 0x00355ab5 find-first (pattern path,
WIN32_FIND_DATA 0x140: attributes +0, FILETIMEs +4/+12/+20, size +28/+32, name +44), 0x00355bc2 find-next (0 and
GetLastError 18 at the end), 0x00355c13 `CreateDirectory(path, 0)` (vfunc_15, parents made, 183 if present), 0x00355c7f
`RemoveDirectory(path)` (vfunc_16, 145 if not empty). Find handles close with CloseHandle. Wildcards `*` `?`
(case-insensitive); results sorted; `.`/`..` not listed; missing directory 3, no match 2.

## Saves

Verified callers: `core::XboxSaveDrive` (equivalent/0x00279630 open, 0x00279220 / 0x002793b0 find, 0x00278ab0 delete,
0x00278ef0 / 0x00279490 / 0x00278de0 the signed 8 KB blocks).

- `XCreateSaveGame(root, name UTF-16, disposition, 0, path, size)` -> error code. CREATE_NEW: 183 if present;
  OPEN_EXISTING of a missing save: **3** (the game tests for it); CREATE_ALWAYS empties; OPEN_ALWAYS creates. The path
  is `U:\<12 hex>\` with the trailing backslash (the game appends `SaveImage.xbx` and `save.dat`).
- `XDeleteSaveGame` (0x003563f0: the import table's name carries a second guess), `XFindFirstSaveGame` /
  `XFindNextSaveGame` / `XFindClose`: the find data is 0x344 bytes (the frame size of `vfunc_19`): WIN32_FIND_DATA
  (0x140), the directory path (260) at +0x140, the save's name UTF-16 (128) at **+0x244** (the game compares it
  with the requested name). -1 + error 18 when there are no saves.
- On disk (Xbox structure as publicly described): `U:\TitleMeta.xbx` (`TitleName=...`), `U:\<dir>\SaveMeta.xbx`
  (UTF-16LE with a byte order mark, `Name=<save name>\r\n`), the game's files. The directory name is **ours**: 12 hex
  digits of a 64-bit FNV-1a hash of the name, probed forward on a clash with another name. The hardware's naming could
  not be verified here.
- `XCalculateSignatureBegin(0)/Update/End` -> 20 bytes: **HMAC-SHA1** (our implementation, checked against the SHA-1 and
  RFC 2202 vectors) under a key derived from the title id and the flags. The Xbox's key is secret
  (console firmware + certificate), so a console save does not verify here and ours does not verify there; the
  game's verification is consistent with our writer (chunking-independent, deterministic, flag-dependent in the tests).
  Importing a real Xbox save would need re-signing.
- `XFormatUtilityDrive` empties `Z:`; `XMountMUA` -> 1167 (no memory units; the controller layer never reports one),
  `XUnmountMU` 0, `XMUNameFromDriveLetter` 1167.

## Limits

- Windows/Wine host: SDL opens files shared for reading only, so a second handle on a file another handle has open for
  writing fails (32). The game closes before reopening in the verified paths; POSIX hosts are unaffected.
- hEvent of an OVERLAPPED is not signalled (nothing in the game uses it).
- `hulk_crt_host_path` (crt_glue.cpp, native9's) still maps `fopen` paths with its own, case-sensitive rule;
  `hulk_fs_map_path` is the replacement (build/fs1/for-native9.md).
