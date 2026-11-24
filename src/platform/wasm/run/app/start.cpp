// The app's start-up: where the game is (docs/wasm-port.md "The macOS app", "First launch"; wui1).
//
// The game is the player's own disc: the extracted folder (default.xbe and the .rcf archives next to it), the Xbox
// disc image (.iso, read in place) or a disc pack (tools/disc_pack.py, .hulkdisc); run/disc.h reads all three, an
// image's files named as if it were the folder (<image>/default.xbe). In order:
//   1. the command line: `hulk-app <path>/default.xbe` (argv[1]) or HULK_XBE, with HULK_DATA_DIR (default: the XBE's
//      folder); HULK_DATA_DIR alone means <it>/default.xbe. Never a window: replays and tests pass the XBE.
//   2. a game bundled with the app (`tools/wasm_app.py bundle --with-game`): Contents/Resources/game.hulkdisc (or
//      game.iso) beside the executable's folder;
//   3. the remembered choice: <app dir>/game.txt (one line, the disc folder or image);
//   4. <app dir>/disc (the extracted disc copied there by hand), <app dir>/disc.hulkdisc or <app dir>/disc.iso;
//   5. a chooser: an alert (Choose Folder... / Choose File... / Quit), then the system's open panel (SDL3's file
//      dialog, NSOpenPanel): a folder, or default.xbe, an .iso or a .hulkdisc. The choice is checked (below) and
//      remembered in game.txt; a bad one says why and asks again.
// `--choose-game` as the first argument, or holding Option at launch, goes to the chooser even when a game is
// remembered (`open Hulk.app --args --choose-game`). <app dir> is HULK_APP_DIR, default
// ~/Library/Application Support/HulkUD; saves go to <app dir>/save unless HULK_SAVE_DIR says otherwise.
// Runs that must not prompt (HULK_NO_UI=1, or a scripted run: HULK_INPUT / HULK_KEY_SCRIPT /
// HULK_INPUT_SOURCE / HULK_CKPT) exit with
// the reason instead of showing the chooser.
//
// The check reads the player's file at run time: an XBE header ("XBEH") whose certificate carries the game's title
// ID, and rcfs.txt with every archive it lists. Nothing of the game is in this source but that ID.
#include <dlfcn.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <unistd.h>

#include <SDL3/SDL.h>
#if defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

#include "../disc.h"
// The build's id (wver1): the short commit, "+dirty" (a local build with uncommitted host files) or "+N" (a queue
// build with N overlay files), from the generated <build dir>/aot/app-gen/hulk_build_id.h (tools/wasm_app.py build,
// wasm_android.py build). Host-only: printed at start, put in the window's title and the bundle's Info.plist / the
// APK's versionName; it never reaches the module's memory.
#if __has_include("hulk_build_id.h")
#include "hulk_build_id.h"
#endif
#ifndef HULK_BUILD_ID
#define HULK_BUILD_ID "unknown"
#endif
// (the tag lets tools/wasm_app.py bundle read the id from the executable itself)
__attribute__((used)) static const char kBuildIdTag[] = "HULK_BUILD_ID=" HULK_BUILD_ID;
extern "C" const char* hulk_app_build_id(void) { return kBuildIdTag + 14; }

static const uint32_t kTitleId = 0x56550039;       // the certificate's title ID of The Incredible Hulk: UD

static bool isDir(const char* p)
{
    struct stat st;
    return !stat(p, &st) && S_ISDIR(st.st_mode);
}

static bool isFile(const char* p)
{
    struct stat st;
    return !stat(p, &st) && S_ISREG(st.st_mode);
}

// a file of the disc (a folder's or an image's), whole up to len bytes; the bytes read, or -1
static long readDiscFile(const char* p, void* buf, size_t len, uint64_t off = 0)
{
    int fd = hdisc_open(p);
    if (fd < 0) return -1;
    long n = (long)hdisc_pread(fd, buf, len, off);
    hdisc_close(fd);
    return n;
}

static const char* endsWith(const char* s, const char* suf)
{
    size_t n = strlen(s), m = strlen(suf);
    return n >= m && !strcasecmp(s + n - m, suf) ? s + n - m : nullptr;
}

// The app bundle's Contents/Resources (macOS: the executable's ../Resources), or null outside a bundle
extern "C" const char* hulk_app_resources_dir(void)
{
    static char dir[PATH_MAX];
    static int done;
    if (done++) return dir[0] ? dir : nullptr;
#if defined(__APPLE__)
    char exe[PATH_MAX], real[PATH_MAX];
    uint32_t n = sizeof exe;
    if (_NSGetExecutablePath(exe, &n) == 0 && realpath(exe, real)) {
        char* slash = strrchr(real, '/');
        if (slash) {
            *slash = 0;
            char r[PATH_MAX + 16];
            snprintf(r, sizeof r, "%s/../Resources", real);
            if (isDir(r) && realpath(r, dir)) return dir;
        }
    }
#endif
    dir[0] = 0;
    return nullptr;
}

// Is `dir` the game's disc (a folder, an .iso or a disc pack)? Empty `why` when it is.
static void checkDisc(const char* dir, char* why, size_t whyLen)
{
    char p[1200];
    why[0] = 0;
    snprintf(p, sizeof p, "%s/default.xbe", dir);
    uint8_t h[0x200];
    long n = readDiscFile(p, h, sizeof h);
    if (n < 0) {
        snprintf(why, whyLen, "There is no default.xbe in\n%s.", dir);
        return;
    }
    uint32_t base = 0, cert = 0, id = 0;
    bool ok = n >= 0x120 && !memcmp(h, "XBEH", 4);
    if (ok) {
        memcpy(&base, h + 0x104, 4);
        memcpy(&cert, h + 0x118, 4);
        uint8_t c[12];
        ok = cert > base && readDiscFile(p, c, sizeof c, cert - base) == (long)sizeof c;
        if (ok) memcpy(&id, c + 8, 4);
    }
    if (!ok) {
        snprintf(why, whyLen, "%s is not an Xbox executable (XBE).", p);
        return;
    }
    if (id != kTitleId) {
        snprintf(why, whyLen, "%s is another Xbox game (title ID %08X), not The Incredible Hulk: Ultimate "
                 "Destruction.", p, id);
        return;
    }
    // the archives the game mounts are the ones its rcfs.txt lists (comma-separated, then the game's own arguments)
    snprintf(p, sizeof p, "%s/rcfs.txt", dir);
    char list[1024] = {0};
    if (readDiscFile(p, list, sizeof list - 1) <= 0) {
        snprintf(why, whyLen, "rcfs.txt is missing from\n%s.\nCopy the whole disc, not only default.xbe.", dir);
        return;
    }
    char missing[512] = {0};
    int nMissing = 0;
    for (char* t = strtok(list, ", \t\r\n"); t; t = strtok(nullptr, ", \t\r\n")) {
        if (!endsWith(t, ".rcf"))
            continue;
        snprintf(p, sizeof p, "%s/%s", dir, t);
        if (hdisc_kind(p) != HDISC_FILE && strlen(missing) + strlen(t) + 3 < sizeof missing) {
            if (nMissing++) strcat(missing, ", ");
            strcat(missing, t);
        }
    }
    if (nMissing)
        snprintf(why, whyLen, "The disc in\n%s\nis incomplete: %s %s missing.\nCopy the whole disc.", dir, missing,
                 nMissing > 1 ? "are" : "is");
}

static void useDisc(const char* dir)
{
    char p[1200];
    snprintf(p, sizeof p, "%s/default.xbe", dir);
    setenv("HULK_XBE", p, 1);
    setenv("HULK_DATA_DIR", dir, 1);
}

// the remembered disc folder (empty when none)
static void readRemembered(const char* file, char* out, size_t len)
{
    out[0] = 0;
    FILE* f = fopen(file, "r");
    if (!f) return;
    if (fgets(out, (int)len, f))
        out[strcspn(out, "\r\n")] = 0;
    fclose(f);
}

static void remember(const char* file, const char* dir)
{
    char tmp[1200];
    snprintf(tmp, sizeof tmp, "%s.tmp", file);
    FILE* f = fopen(tmp, "w");
    if (!f) return;
    fprintf(f, "%s\n", dir);
    if (fclose(f) == 0) rename(tmp, file);
}

static bool optionHeld()
{
    // CoreGraphics' CGEventSourceFlagsState (combined session state, the Option mask), loaded with AppKit
    typedef uint64_t (*FlagsState)(int32_t);
    FlagsState fn = (FlagsState)dlsym(RTLD_DEFAULT, "CGEventSourceFlagsState");
    return fn && (fn(0) & 0x00080000);
}

static bool mayPrompt()
{
    const char* e = getenv("HULK_NO_UI");
    if (e && *e && strcmp(e, "0")) return false;
    return !getenv("HULK_INPUT") && !getenv("HULK_KEY_SCRIPT") && !getenv("HULK_INPUT_SOURCE") && !getenv("HULK_CKPT") &&
           !getenv("HULK_RECORD_BASE");
}

struct Pick { bool done, failed; char path[1024]; };

static void SDLCALL onPicked(void* ud, const char* const* files, int)
{
    Pick* p = (Pick*)ud;
    p->done = true;
    p->path[0] = 0;
    p->failed = !files;             // (NULL: the dialog failed; an empty list: cancelled)
    if (files && files[0]) snprintf(p->path, sizeof p->path, "%s", files[0]);
}

// The chooser: true with `dir` set to a checked disc folder, false when the player quits.
static bool chooseGame(char* dir, size_t len, const char* firstError)
{
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        fprintf(stderr, "hulk-app: no display for the game chooser (%s)\n", SDL_GetError());
        return false;
    }
    char why[1600];
    snprintf(why, sizeof why, "%s", firstError ? firstError : "");
    bool chosen = false;
    for (;;) {
        char msg[2200];
        snprintf(msg, sizeof msg, "%s%sHulk needs your own copy of the game: choose the extracted disc folder, or a "
                 "file: its default.xbe, the Xbox disc image (.iso) or a disc pack (.hulkdisc).",
                 why, why[0] ? "\n\n" : "");
        const SDL_MessageBoxButtonData buttons[] = {
            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Choose Folder\xE2\x80\xA6"},
            {0, 2, "Choose File\xE2\x80\xA6"},
            {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "Quit"},
        };
        const SDL_MessageBoxData box = {why[0] ? SDL_MESSAGEBOX_WARNING : SDL_MESSAGEBOX_INFORMATION, nullptr,
                                        why[0] ? "Hulk UD: that is not the game" : "Hulk UD: find your game", msg,
                                        SDL_arraysize(buttons), buttons, nullptr};
        int b = 0;
        if (!SDL_ShowMessageBox(&box, &b) || b == 0)
            break;
        Pick pick = {};
        if (b == 1) {
            SDL_ShowOpenFolderDialog(onPicked, &pick, nullptr, nullptr, false);
        } else {
            static const SDL_DialogFileFilter xbe[] = {
                {"The game (default.xbe, disc image, disc pack)", "xbe;iso;hulkdisc"}};
            SDL_ShowOpenFileDialog(onPicked, &pick, nullptr, xbe, 1, nullptr, false);
        }
        while (!pick.done) {            // (with no window the panel is modal: the callback has run already)
            SDL_PumpEvents();
            SDL_Delay(10);
        }
        if (pick.failed) {
            snprintf(why, sizeof why, "The file dialog failed (%s). Pass the game on the command line: hulk-app "
                     "<disc>/default.xbe.", SDL_GetError());
            fprintf(stderr, "hulk-app: %s\n", why);
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Hulk UD", why, nullptr);
            break;
        }
        if (!pick.path[0]) {            // cancelled: back to the alert
            why[0] = 0;
            continue;
        }
        char d[1024];
        snprintf(d, sizeof d, "%s", pick.path);
        if (isFile(d) && !hdisc_source(d)) {    // default.xbe itself: its folder is the disc (an image is one)
            char* slash = strrchr(d, '/');
            if (slash) *slash = 0;
        }
        checkDisc(d, why, sizeof why);
        if (!why[0]) {
            snprintf(dir, len, "%s", d);
            chosen = true;
            break;
        }
        fprintf(stderr, "hulk-app: %s\n", why);
    }
    SDL_QuitSubSystem(SDL_INIT_VIDEO);  // (the game's window opens its own)
    return chosen;
}

// A run that is not the player at the controls: test input, a replay, checkpoints, a rollback test, no UI (whang1)
static bool scriptedRun()
{
    const char* e = getenv("HULK_NO_UI");
    if (e && *e && strcmp(e, "0")) return true;
    return getenv("HULK_INPUT") || getenv("HULK_KEY_SCRIPT") || getenv("HULK_INPUT_SOURCE") || getenv("HULK_CKPT") ||
           getenv("HULK_ROLLTEST") || getenv("HULK_RECORD_BASE");      // (a playthrough session: tools/playthrough.py)
}

// PATH is in (or is) the player's default app folder, ~/Library/Application Support/HulkUD (whang1)
static bool inPlayerFolder(const char* path)
{
    const char* home = getenv("HOME");
    if (!home || !*home) return false;
    char def[1100], a[PATH_MAX], b[PATH_MAX];
    snprintf(def, sizeof def, "%s/Library/Application Support/HulkUD", home);
    const char* d = realpath(def, a) ? a : def;
    // the save folder may not exist yet: resolve its longest existing parent
    char p[PATH_MAX];
    snprintf(p, sizeof p, "%s", path);
    const char* q = 0;
    char rest[PATH_MAX] = "";
    while (!(q = realpath(p, b))) {
        char* slash = strrchr(p, '/');
        if (!slash || slash == p) break;
        char tmp[PATH_MAX];
        snprintf(tmp, sizeof tmp, "%s%s", slash, rest);
        snprintf(rest, sizeof rest, "%s", tmp);
        *slash = 0;
    }
    char full[PATH_MAX * 2];
    snprintf(full, sizeof full, "%s%s", q ? q : path, q ? rest : "");
    size_t n = strlen(d);
    return !strncasecmp(full, d, n) && (full[n] == 0 || full[n] == '/');
}

// The app's end (run/native.c's proc_exit: the game's ExitProcess, which the window's close button, Cmd+Q and the
// menus' Quit lead to; src/platform/wasm/gfx/gfx.c hulk_platform_quit_requested): the movies, the audio and SDL closed
// before the process exits with the game's code.
extern "C" void hulk_app_movie_quit(void);     // run/app/movie.c
extern "C" void hulk_app_audio_quit(void);     // run/app/audio.cpp
extern "C" int hulk_app_pad_stop(unsigned wait_ms);     // run/app/input.cpp
extern "C" void hulk_app_quit(int code)
{
    static bool once;
    if (once)
        return;
    once = true;
    hulk_app_movie_quit();
    hulk_app_audio_quit();
    // a controller thread stuck in SDL's gamepad init holds SDL's joystick lock, which SDL_Quit would wait on forever
    // (wpad1): then the process exit ends SDL instead
    if (hulk_app_pad_stop(300))
        SDL_Quit();
    fprintf(stderr, "hulk-app: quit (exit code %d)\n", code);
    fflush(stderr);
}

// HULK_GFX_RENDERER: metal (the app's default) | noop | null (the game's own d3d layer on the null device: the
// headless build's run, for the replay check). Then the game, as above. Consumes `--choose-game` from argv.
extern "C" void hulk_app_start(int* argc, char** argv)
{
    printf("hulk-app: build %s\n", HULK_BUILD_ID);
    fflush(stdout);
    setenv("HULK_GFX_RENDERER", "metal", 0);
    bool choose = false;
    if (*argc > 1 && !strcmp(argv[1], "--choose-game")) {
        choose = true;
        for (int i = 1; i < *argc; i++) argv[i] = argv[i + 1];
        (*argc)--;
    }
    char app[1024], path[1200];
    const char* home = getenv("HOME");
    if (getenv("HULK_APP_DIR") && *getenv("HULK_APP_DIR"))
        snprintf(app, sizeof app, "%s", getenv("HULK_APP_DIR"));
    else if (home)
        snprintf(app, sizeof app, "%s/Library/Application Support/HulkUD", home);
    else
        app[0] = 0;
    // The saves (whang1). Only an interactive launch (no script, test or replay variable) saves in the player's
    // folder, <app dir>/save, also when the game comes from the command line. A scripted, automated or test run
    // (HULK_INPUT, HULK_KEY_SCRIPT, HULK_INPUT_SOURCE, HULK_CKPT, HULK_ROLLTEST, HULK_NO_UI) never defaults to it:
    // it keeps a run-local folder (HULK_SAVE_DIR, else build/wasm/save under the working directory), and a
    // HULK_SAVE_DIR inside the player's default folder (~/Library/Application Support/HulkUD) is refused unless the
    // test set HULK_APP_DIR. Before this, a game given on the command line skipped this, and a launch with `open`
    // (working directory /) had no writable save folder: the game then waits at a mission's summary for a save that
    // never succeeds.
    if (scriptedRun()) {
        const char* sd = getenv("HULK_SAVE_DIR");   // (unset: the host's default; not set here, so the module's
        if (sd && *sd &&                           // environment and its C library's heap bytes stay as they were)
            !(getenv("HULK_APP_DIR") && *getenv("HULK_APP_DIR")) && inPlayerFolder(sd)) {
            fprintf(stderr, "hulk-app: a scripted run may not save in the player's folder (%s): set another "
                            "HULK_SAVE_DIR, or HULK_APP_DIR for a test's own app folder\n", sd);
            exit(2);
        }
    } else if (app[0]) {
        mkdir(app, 0755);
        snprintf(path, sizeof path, "%s/save", app);
        mkdir(path, 0755);
        setenv("HULK_SAVE_DIR", path, 0);
    }
    const char* saves = getenv("HULK_SAVE_DIR");
    fprintf(stderr, "hulk-app: saves in %s\n", saves && *saves ? saves : "build/wasm/save (the working directory's)");

    if (*argc > 1 || getenv("HULK_XBE"))           // 1. the command line (the runner takes argv[1] first)
        return;
    const char* dataDir = getenv("HULK_DATA_DIR");
    if (dataDir && *dataDir) {
        char p[1200];
        snprintf(p, sizeof p, "%s/default.xbe", dataDir);
        setenv("HULK_XBE", p, 1);
        return;
    }
    if (!app[0]) {
        fprintf(stderr, "hulk-app: no HOME: pass the game's default.xbe\n");
        exit(2);
    }
    char remembered[1100];
    snprintf(path, sizeof path, "%s/game.txt", app);
    readRemembered(path, remembered, sizeof remembered);

    char why[1600] = {0};
    if (!choose && !optionHeld()) {
        const char* res = hulk_app_resources_dir();  // 2. a game bundled with the app
        static const char* const kBundled[] = {"game.hulkdisc", "game.iso"};
        for (const char* name : kBundled) {
            char g[1200], gWhy[1600];
            if (!res) break;
            snprintf(g, sizeof g, "%s/%s", res, name);
            if (!isFile(g)) continue;
            checkDisc(g, gWhy, sizeof gWhy);
            if (!gWhy[0]) {
                fprintf(stderr, "hulk-app: the game bundled with the app (%s)\n", g);
                useDisc(g);
                return;
            }
            fprintf(stderr, "hulk-app: the bundled game %s is not usable: %s\n", g, gWhy);
        }
        if (remembered[0]) {                        // 3. the remembered choice
            checkDisc(remembered, why, sizeof why);
            if (!why[0]) {
                useDisc(remembered);
                return;
            }
            fprintf(stderr, "hulk-app: the remembered game (%s) is gone or changed: %s\n", path, why);
            char was[1600];
            snprintf(was, sizeof was, "The game chosen before is gone or changed. %s", why);
            snprintf(why, sizeof why, "%s", was);
        }
        static const char* const kAppDisc[] = {"disc", "disc.hulkdisc", "disc.iso"};
        for (const char* name : kAppDisc) {         // 4. <app dir>/disc (a folder or an image)
            char disc[1100];
            snprintf(disc, sizeof disc, "%s/%s", app, name);
            char discWhy[1600];
            checkDisc(disc, discWhy, sizeof discWhy);
            if (!discWhy[0]) {
                useDisc(disc);
                return;
            }
            if (!why[0] && (isDir(disc) || isFile(disc))) snprintf(why, sizeof why, "%s", discWhy);
        }
    }
    if (!mayPrompt()) {
        fprintf(stderr, "hulk-app: no game: pass <disc>/default.xbe (this run does not prompt: HULK_NO_UI or a "
                "scripted run)%s%s\n", why[0] ? ": " : "", why);
        exit(2);
    }
    char dir[1024];                                 // 5. the chooser
    if (!chooseGame(dir, sizeof dir, why[0] ? why : nullptr)) {
        fprintf(stderr, "hulk-app: no game chosen\n");
        exit(2);
    }
    remember(path, dir);
    fprintf(stderr, "hulk-app: game %s (remembered in %s)\n", dir, path);
    useDisc(dir);
}
