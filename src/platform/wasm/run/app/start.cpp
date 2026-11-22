// The app's start-up: where the game is (docs/wasm-port.md "The macOS app", "First launch"; wui1).
//
// The game is the player's own extracted disc: default.xbe and the .rcf archives next to it. In order:
//   1. the command line: `hulk-app <path>/default.xbe` (argv[1]) or HULK_XBE, with HULK_DATA_DIR (default: the XBE's
//      folder); HULK_DATA_DIR alone means <it>/default.xbe. Never a window: replays and tests pass the XBE.
//   2. the remembered choice: <app dir>/game.txt (one line, the disc folder);
//   3. <app dir>/disc (the extracted disc copied there by hand);
//   4. a chooser: an alert (Choose Folder... / Choose default.xbe... / Quit), then the system's open panel (SDL3's
//      file dialog, NSOpenPanel). The choice is checked (below) and remembered in game.txt; a bad one says why and
//      asks again.
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
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <SDL3/SDL.h>

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

static const char* endsWith(const char* s, const char* suf)
{
    size_t n = strlen(s), m = strlen(suf);
    return n >= m && !strcasecmp(s + n - m, suf) ? s + n - m : nullptr;
}

// Is `dir` an extracted disc of the game? Empty `why` when it is.
static void checkDisc(const char* dir, char* why, size_t whyLen)
{
    char p[1200];
    why[0] = 0;
    snprintf(p, sizeof p, "%s/default.xbe", dir);
    FILE* f = fopen(p, "rb");
    if (!f) {
        snprintf(why, whyLen, "There is no default.xbe in\n%s.", dir);
        return;
    }
    uint8_t h[0x200];
    size_t n = fread(h, 1, sizeof h, f);
    uint32_t base = 0, cert = 0, id = 0;
    bool ok = n >= 0x120 && !memcmp(h, "XBEH", 4);
    if (ok) {
        memcpy(&base, h + 0x104, 4);
        memcpy(&cert, h + 0x118, 4);
        uint8_t c[12];
        ok = cert > base && !fseek(f, (long)(cert - base), SEEK_SET) && fread(c, 1, sizeof c, f) == sizeof c;
        if (ok) memcpy(&id, c + 8, 4);
    }
    fclose(f);
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
    f = fopen(p, "rb");
    char list[1024] = {0};
    if (!f || !fread(list, 1, sizeof list - 1, f)) {
        if (f) fclose(f);
        snprintf(why, whyLen, "rcfs.txt is missing from\n%s.\nCopy the whole disc, not only default.xbe.", dir);
        return;
    }
    fclose(f);
    char missing[512] = {0};
    int nMissing = 0;
    for (char* t = strtok(list, ", \t\r\n"); t; t = strtok(nullptr, ", \t\r\n")) {
        if (!endsWith(t, ".rcf"))
            continue;
        snprintf(p, sizeof p, "%s/%s", dir, t);
        if (!isFile(p) && strlen(missing) + strlen(t) + 3 < sizeof missing) {
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
    return !getenv("HULK_INPUT") && !getenv("HULK_KEY_SCRIPT") && !getenv("HULK_INPUT_SOURCE") && !getenv("HULK_CKPT");
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
        snprintf(msg, sizeof msg, "%s%sHulk needs your own copy of the game: choose the extracted disc folder or its "
                 "default.xbe.\n\nA disc image (.iso) has to be extracted to a folder first.",
                 why, why[0] ? "\n\n" : "");
        const SDL_MessageBoxButtonData buttons[] = {
            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Choose Folder\xE2\x80\xA6"},
            {0, 2, "Choose default.xbe\xE2\x80\xA6"},
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
            static const SDL_DialogFileFilter xbe[] = {{"Xbox executable (default.xbe)", "xbe"}};
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
        if (isFile(d)) {                // default.xbe itself: its folder is the disc
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

// HULK_GFX_RENDERER: metal (the app's default) | noop | null (the game's own d3d layer on the null device: the
// headless build's run, for the replay check). Then the game, as above. Consumes `--choose-game` from argv.
extern "C" void hulk_app_start(int* argc, char** argv)
{
    setenv("HULK_GFX_RENDERER", "metal", 0);
    bool choose = false;
    if (*argc > 1 && !strcmp(argv[1], "--choose-game")) {
        choose = true;
        for (int i = 1; i < *argc; i++) argv[i] = argv[i + 1];
        (*argc)--;
    }
    if (*argc > 1 || getenv("HULK_XBE"))           // 1. the command line (the runner takes argv[1] first)
        return;
    const char* dataDir = getenv("HULK_DATA_DIR");
    if (dataDir && *dataDir) {
        char p[1200];
        snprintf(p, sizeof p, "%s/default.xbe", dataDir);
        setenv("HULK_XBE", p, 1);
        return;
    }

    char app[1024], path[1200];
    const char* home = getenv("HOME");
    if (getenv("HULK_APP_DIR") && *getenv("HULK_APP_DIR"))
        snprintf(app, sizeof app, "%s", getenv("HULK_APP_DIR"));
    else if (home)
        snprintf(app, sizeof app, "%s/Library/Application Support/HulkUD", home);
    else {
        fprintf(stderr, "hulk-app: no HOME: pass the game's default.xbe\n");
        exit(2);
    }
    mkdir(app, 0755);
    snprintf(path, sizeof path, "%s/save", app);
    mkdir(path, 0755);
    setenv("HULK_SAVE_DIR", path, 0);
    char remembered[1100];
    snprintf(path, sizeof path, "%s/game.txt", app);
    readRemembered(path, remembered, sizeof remembered);

    char why[1600] = {0};
    if (!choose && !optionHeld()) {
        if (remembered[0]) {                        // 2. the remembered choice
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
        char disc[1100];                            // 3. <app dir>/disc
        snprintf(disc, sizeof disc, "%s/disc", app);
        char discWhy[1600];
        checkDisc(disc, discWhy, sizeof discWhy);
        if (!discWhy[0]) {
            useDisc(disc);
            return;
        }
        if (!why[0] && isDir(disc)) snprintf(why, sizeof why, "%s", discWhy);
    }
    if (!mayPrompt()) {
        fprintf(stderr, "hulk-app: no game: pass <disc>/default.xbe (this run does not prompt: HULK_NO_UI or a "
                "scripted run)%s%s\n", why[0] ? ": " : "", why);
        exit(2);
    }
    char dir[1024];                                 // 4. the chooser
    if (!chooseGame(dir, sizeof dir, why[0] ? why : nullptr)) {
        fprintf(stderr, "hulk-app: no game chosen\n");
        exit(2);
    }
    remember(path, dir);
    fprintf(stderr, "hulk-app: game %s (remembered in %s)\n", dir, path);
    useDisc(dir);
}
