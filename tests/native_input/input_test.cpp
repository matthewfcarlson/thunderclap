// Input backend smoke test (docs/native-audio-input.md): SDL3 virtual gamepads -> the Xbox controller state the
// game reads (buttons, analog buttons, thumbs, triggers), hot-plug through XGetDeviceChanges' semantics, rumble.
// Host: the typed API (src/platform/sdl/input/hulk_input.h). HULK_TEST_XDK (i686 under Wine): the same through the
// hulk_xdk_* stand-ins with the game's 22-byte XINPUT_STATE and feedback block (src/platform/sdl/xdk/input_xpp.cpp).
#include "input/hulk_input.h"
#include "replay/hulk_replay.h"
#include "../native_audio/test_common.h"

#ifdef HULK_TEST_XDK
#include "xdk/imports.h"
extern "C" hulk_u32 hulk_lib_xpp_gamepad_type[1];
extern "C" hulk_u32 hulk_lib_xpp_mu_type[1];
#endif

// ---------------------------------------------------------------------------------------------
// virtual pads
struct Rumble {
    int calls;
    Uint16 low, high;
};
static Rumble g_rumble[2];

static bool SDLCALL rumble_cb(void* user, Uint16 low, Uint16 high)
{
    Rumble* r = (Rumble*)user;
    r->calls++;
    r->low = low;
    r->high = high;
    return true;
}

static SDL_JoystickID attach(int which)
{
    SDL_VirtualJoystickDesc d;
    SDL_INIT_INTERFACE(&d);
    d.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    d.naxes = SDL_GAMEPAD_AXIS_COUNT;
    d.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    d.axis_mask = (1u << SDL_GAMEPAD_AXIS_COUNT) - 1;
    d.button_mask = (1u << SDL_GAMEPAD_BUTTON_COUNT) - 1;
    d.name = which ? "hulk virtual pad 2" : "hulk virtual pad 1";
    d.userdata = &g_rumble[which];
    d.Rumble = rumble_cb;
    SDL_JoystickID id = SDL_AttachVirtualJoystick(&d);
    CHECK(id != 0, "attach virtual pad: %s", SDL_GetError());
    return id;
}

// ---------------------------------------------------------------------------------------------
// the API under test (the gamepad state as the game sees it: 22 bytes, packet number first)
#ifdef HULK_TEST_XDK
typedef hulk_u32 H;
static hulk_u32 pad_type() { return TEST_PTR(hulk_lib_xpp_gamepad_type); }
static void api_init() { hulk_xdk_XInitDevices(0, 0); }
static int changes(unsigned* ins, unsigned* rem)
{
    hulk_u32 i = 0xdead, r = 0xdead;
    int any = (int)hulk_xdk_XGetDeviceChanges(pad_type(), TEST_PTR(&i), TEST_PTR(&r));
    *ins = i;
    *rem = r;
    return any;
}
static unsigned devices() { return hulk_xdk_XGetDevices(pad_type()); }
static H open_port(unsigned port) { return hulk_xdk_XInputOpen(pad_type(), port, 0, 0); }
static void close_h(H h) { hulk_xdk_XInputClose(h); }
static unsigned get_state(H h, unsigned* packet, HulkPadState* s)
{
    unsigned char st[22];
    SDL_memset(st, 0xcc, sizeof(st));
    unsigned rc = hulk_xdk_XInputGetState(h, TEST_PTR(st));
    SDL_memcpy(packet, st, 4);
    SDL_memcpy(&s->buttons, st + 4, 2);
    SDL_memcpy(s->analog, st + 6, 8);
    SDL_memcpy(s->thumb, st + 14, 8);
    return rc;
}
static unsigned set_rumble(H h, unsigned short l, unsigned short r)
{
    // the game's feedback block (ControllerXBox +0x458): status, ..., motors at +0x42
    unsigned char fb[0x46];
    SDL_memset(fb, 0, sizeof(fb));
    hulk_u32 pending = 997;                            // ERROR_IO_PENDING, as the game leaves it
    SDL_memcpy(fb, &pending, 4);
    SDL_memcpy(fb + 0x42, &l, 2);
    SDL_memcpy(fb + 0x44, &r, 2);
    hulk_xdk_XInputSetState(h, TEST_PTR(fb));
    hulk_u32 status;
    SDL_memcpy(&status, fb, 4);
    return status;
}
#else
typedef int H;                                         // the port + 1 (0: none), and the generation it was opened at
static unsigned g_open_gen[8];
static void api_init() { hulk_input_init(); }
static int changes(unsigned* ins, unsigned* rem) { return hulk_input_changes(ins, rem); }
static unsigned devices() { return hulk_input_devices(); }
static H open_port(unsigned port)
{
    if (!(hulk_input_devices() & (1u << port)))
        return 0;
    g_open_gen[port] = hulk_input_generation(port);
    return (H)port + 1;
}
static void close_h(H) {}
static unsigned g_packet[4];
static HulkPadState g_last[4];
static unsigned get_state(H h, unsigned* packet, HulkPadState* s)
{
    unsigned port = (unsigned)h - 1;
    if (!h || hulk_input_generation(port) != g_open_gen[port] || !hulk_input_read(port, s))
        return 1167;
    if (SDL_memcmp(s, &g_last[port], sizeof(*s)) != 0)
        g_packet[port]++;
    g_last[port] = *s;
    *packet = g_packet[port];
    return 0;
}
static unsigned set_rumble(H h, unsigned short l, unsigned short r)
{
    hulk_input_rumble((unsigned)h - 1, l, r);
    return 0;
}
#endif

static void settle()
{
    SDL_Delay(5);                                      // past the backend's 2 ms poll interval
}


// ---------------------------------------------------------------------------------------------
// recorded input (rp1): the replay source, with the hybrid build's poll semantics (docs/native-replay.md)
#include "synth_replay.inc"      // kSynthJson, kSynthHrp: tools/replay_pack.py synth

static void pad_bytes(const HulkPadState& s, unsigned char* b)      // the 18 bytes of XINPUT_GAMEPAD
{
    b[0] = (unsigned char)s.buttons;
    b[1] = (unsigned char)(s.buttons >> 8);
    for (int i = 0; i < 8; i++)
        b[2 + i] = s.analog[i];
    for (int i = 0; i < 4; i++) {
        b[10 + 2 * i] = (unsigned char)s.thumb[i];
        b[11 + 2 * i] = (unsigned char)((unsigned short)s.thumb[i] >> 8);
    }
}

static unsigned fnv_bytes(unsigned h, const unsigned char* p, int n)
{
    for (int i = 0; i < n; i++)
        h = (h ^ p[i]) * 16777619u;
    return h;
}

// the synthetic recording by hand (tests/native_input/synth_replay.json: entries at polls 3, 5, 8, 10, 14, 21)
static HulkPadState synth_expect(unsigned poll)
{
    HulkPadState s;
    SDL_memset(&s, 0, sizeof(s));
    if (poll >= 5 && poll < 8)
        s.buttons = HULK_PAD_START;
    if (poll >= 10 && poll < 14)
        s.analog[HULK_PAD_A] = 255;
    if (poll >= 14 && poll < 21) {
        s.buttons = HULK_PAD_DPAD_UP | HULK_PAD_DPAD_DOWN;
        s.analog[HULK_PAD_B] = 255;
        s.analog[HULK_PAD_LEFT_TRIGGER] = 128;
        s.analog[HULK_PAD_RIGHT_TRIGGER] = 255;
        s.thumb[0] = -15360;
        s.thumb[1] = 31744;
        s.thumb[2] = -32768;
        s.thumb[3] = 32767;
    }
    if (poll >= 21) {
        s.thumb[2] = 100;
        s.thumb[3] = -100;
    }
    return s;
}

static unsigned stream_hash(unsigned polls, unsigned port = 0)
{
    unsigned h = 2166136261u;
    for (unsigned p = 1; p <= polls; p++) {
        HulkPadState s;
        if (!hulk_input_read(port, &s))
            return 0;
        unsigned char b[18];
        pad_bytes(s, b);
        h = fnv_bytes(h, b, 18);
    }
    return h;
}

static void use_replay()
{
    hulk_input_shutdown();
    hulk_input_set_source(hulk_replay_source());
    hulk_input_init();
}

static void replay_checks()
{
    // load: JSON text and the packed form carry the same recording
    CHECK(hulk_replay_open_memory(kSynthJson, sizeof(kSynthJson) - 1), "open synth json: %s", hulk_replay_error());
    HulkReplayInfo ri;
    CHECK(hulk_replay_info(&ri) && ri.entries == 6 && ri.checkpoints == 3 && ri.seed == 4660 && ri.tweaks == 3 &&
              ri.vpad_count == 1 && !ri.frame_keyed && !ri.autostart && (ri.flags & 64) && (ri.flags & 2048) &&
              (ri.flags & 8192),
          "json info: %u entries %u ckpts seed %u tweaks %u pads %u keyed %d flags %x", ri.entries, ri.checkpoints,
          ri.seed, ri.tweaks, ri.vpad_count, ri.frame_keyed, ri.flags);
    use_replay();
    CHECK(SDL_strcmp(hulk_input_source()->name, "replay") == 0, "source name");

    // one virtual pad, inserted at the first device check, once
    unsigned ins = 0, rem = 0;
    CHECK(hulk_input_devices() == 1, "devices %x", hulk_input_devices());
    CHECK(hulk_input_changes(&ins, &rem) && ins == 1 && rem == 0, "insertion: %x %x", ins, rem);
    CHECK(!hulk_input_changes(&ins, &rem) && ins == 0 && rem == 0, "no second insertion");

    // the pad-init reads (20 per pad object) are idle and not polls
    int idle = 1;
    for (int i = 0; i < 20; i++) {
        HulkPadState s;
        unsigned char b[18];
        idle = idle && hulk_input_read_init(0, &s);
        pad_bytes(s, b);
        for (int k = 0; k < 18; k++)
            idle = idle && b[k] == 0;
    }
    CHECK(idle, "init reads are idle pad reads");
    CHECK(hulk_replay_info(&ri) && ri.polls == 0, "init reads counted as polls: %u", ri.polls);

    // poll by poll against the hand-written table: before the first entry the pad is idle, a state holds until
    // the next entry, and after the last entry it holds for good
    int bad = 0;
    for (unsigned p = 1; p <= 40; p++) {
        HulkPadState s, e = synth_expect(p);
        unsigned char sb[18], eb[18];
        if (!hulk_input_read(0, &s))
            bad++;
        pad_bytes(s, sb);
        pad_bytes(e, eb);
        if (SDL_memcmp(sb, eb, 18) != 0) {
            bad++;
            printf("  poll %u: buttons %x vs %x\n", p, s.buttons, e.buttons);
        }
    }
    CHECK(bad == 0, "%d polls differ from the table", bad);
    CHECK(hulk_replay_info(&ri) && ri.polls == 40 && ri.pos == 5, "polls %u pos %u", ri.polls, ri.pos);

    // a port with no virtual pad: no read, and not a poll
    HulkPadState s;
    CHECK(!hulk_input_read(1, &s), "port 1 reads");
    CHECK(hulk_replay_info(&ri) && ri.polls == 40, "a failed read counted as a poll");
    hulk_input_rumble(0, 0x8000, 0x4000);                 // ignored

    // json and .hrp give the same stream (and the one tools/replay_pack.py stream computes)
    CHECK(hulk_replay_open_memory(kSynthJson, sizeof(kSynthJson) - 1), "reopen json");
    use_replay();
    unsigned hj = stream_hash(25);
    CHECK(hulk_replay_open_memory(kSynthHrp, sizeof(kSynthHrp)), "open synth hrp: %s", hulk_replay_error());
    CHECK(hulk_replay_info(&ri) && ri.entries == 6 && ri.checkpoints == 3 && ri.seed == 4660 && ri.tweaks == 3,
          "hrp info");
    use_replay();
    unsigned hh = stream_hash(25);
    printf("replay-stream %08x polls 25\n", hh);
    CHECK(hj == hh && hh == 0x7e948749u, "stream hashes: json %08x hrp %08x (tools/replay_pack.py: 7e948749)", hj, hh);

    // two virtual pads share one poll counter (recordings made before the single virtual pad: vpad_count)
    static const char two[] = "{\"version\": 2, \"key\": \"polls\", \"flags\": [\"pollkey\", \"vpad\"], \"vpad_count\": 2,"
                              " \"inputs\": [[1, 0, [], []], [3, 1, [], []], [6, 0, [], [1, 2, 3, 4]]]}";
    CHECK(hulk_replay_open_memory(two, sizeof(two) - 1), "open two-pad: %s", hulk_replay_error());
    use_replay();
    CHECK(hulk_input_devices() == 3 && hulk_input_changes(&ins, &rem) && ins == 3, "two pads inserted: %x", ins);
    unsigned got[8];
    for (unsigned p = 1; p <= 7; p++) {
        HulkPadState t;
        hulk_input_read((p - 1) & 1, &t);               // polls alternate port 0, 1, 0, 1...
        got[p] = t.buttons | (t.thumb[3] << 8);
    }
    CHECK(got[1] == 0 && got[2] == 0 && got[3] == 1 && got[4] == 1 && got[5] == 1 && got[6] == (4 << 8) &&
              got[7] == (4 << 8),
          "two-pad polls: %x %x %x %x %x %x %x", got[1], got[2], got[3], got[4], got[5], got[6], got[7]);
    CHECK(hulk_replay_info(&ri) && ri.polls == 7, "two-pad poll count %u", ri.polls);

    // the old frame-keyed lists (tests/replays): the game's frame counter keys them; the auto-START rule taps START
    // while the frame counter stands still for more than 60 polls
    static const char legacy[] = "[[5, 16, [], []], [8, 0, [255], [0, 0, 7]]]";
    CHECK(hulk_replay_open_memory(legacy, sizeof(legacy) - 1), "open legacy list: %s", hulk_replay_error());
    CHECK(hulk_replay_info(&ri) && ri.frame_keyed && ri.autostart && ri.entries == 2, "legacy info");
    use_replay();
    HulkPadState t;
    // without a frame counter the rule is off: a long stall taps nothing
    int quiet = 1;
    for (int n = 0; n < 100; n++) {
        hulk_input_read(0, &t);
        quiet = quiet && t.buttons == 0;
    }
    CHECK(quiet, "auto-START fired without frame reports");
    use_replay();
    hulk_replay_set_frame(4);
    hulk_input_read(0, &t);
    CHECK(t.buttons == 0, "frame 4 before the first entry: %x", t.buttons);
    hulk_replay_set_frame(5);
    hulk_input_read(0, &t);
    CHECK(t.buttons == HULK_PAD_START, "frame 5: %x", t.buttons);
    hulk_replay_set_frame(9);
    hulk_input_read(0, &t);
    CHECK(t.buttons == 0 && t.analog[0] == 255 && t.thumb[2] == 7, "frame 9: %x A %u RX %d", t.buttons, t.analog[0],
          t.thumb[2]);
    unsigned taps = 0, first_tap = 0, last_state = 0;
    for (unsigned n = 1; n <= 100; n++) {                  // the frame stays 9: a stalled loop
        hulk_input_read(0, &t);
        if (t.buttons == HULK_PAD_START && !last_state && !first_tap)
            first_tap = n;
        taps += (t.buttons == HULK_PAD_START && !last_state);
        last_state = t.buttons == HULK_PAD_START;
    }
    // the stall counts polls after the one that moved the frame; START at 61 < stalled <= 64 (bit 3 set), again 72..79
    CHECK(first_tap == 61 && taps == 3, "auto-START: first at stalled poll %u, %u taps", first_tap, taps);
    hulk_replay_set_press_start_ok(0);
    int none = 1;
    for (int n = 0; n < 40; n++) {
        hulk_input_read(0, &t);
        none = none && t.buttons == 0;
    }
    CHECK(none, "auto-START off when the game is not at PRESS START");
    hulk_replay_set_press_start_ok(1);

    // checkpoint hashing: the hybrid hash over stand-in game memory, against the recording's checkpoints that
    // tools/replay_pack.py synth computed independently: frames 0 and 30 agree, 60 was recorded with another RNG state
    unsigned char rng[8], boot[4], camobj[0x60], clockobj[0x40];
    for (int i = 0; i < 8; i++) rng[i] = (unsigned char)(i * 7 + 3);
    for (int i = 0; i < 4; i++) boot[i] = (unsigned char)(i * 7 + 3 + 10);
    for (int i = 0; i < 0x60; i++) camobj[i] = (unsigned char)(i * 7 + 3 + 20);
    for (int i = 0; i < 0x40; i++) clockobj[i] = (unsigned char)(i * 7 + 3 + 40);
    const void* camptr = camobj;
    HulkCkptState gs = {rng, boot, &camptr, clockobj, 0};
    CHECK(hulk_replay_open_memory(kSynthJson, sizeof(kSynthJson) - 1), "reopen");
    unsigned want0 = 0, want60 = 0;
    CHECK(hulk_replay_expected_hash(0, &want0) && hulk_replay_expected_hash(60, &want60) &&
              !hulk_replay_expected_hash(7, &want0),
          "expected hashes");
    hulk_replay_expected_hash(0, &want0);
    CHECK(hulk_ckpt_hash(0, &gs) == want0, "frame-0 hash %08x vs recording %08x", hulk_ckpt_hash(0, &gs), want0);
    CHECK(hulk_ckpt_hash(60, &gs) != want60, "frame 60 should differ");
    hulk_ckpt_reset(30);
    int results[61];
    for (int f = 0; f <= 60; f++)
        results[f] = hulk_ckpt_update(&gs);
    HulkCkptStats cs;
    hulk_ckpt_stats(&cs);
    CHECK(cs.frame == 61 && cs.checked == 3 && cs.matched == 2 && cs.mismatched == 1 && cs.unmatched == 0 &&
              cs.first_bad_frame == 60 && results[0] == 1 && results[1] == -1 && results[30] == 1 && results[60] == 0,
          "ckpt: frames %u checked %u matched %u mismatched %u first bad %u", cs.frame, cs.checked, cs.matched,
          cs.mismatched, cs.first_bad_frame);
    // read at GameClock::Update's entry: the previous frame's step and scaled step count as zero (Update clears them
    // before the hybrid build hashes)
    unsigned char clock2[0x40];
    SDL_memcpy(clock2, clockobj, sizeof(clock2));
    unsigned long long stale = 0x1122334455667788ull;
    SDL_memcpy(clock2 + 0x28, &stale, 8);
    SDL_memcpy(clock2 + 0x30, &stale, 8);
    unsigned char clock0[0x40];
    SDL_memcpy(clock0, clockobj, sizeof(clock0));
    SDL_memset(clock0 + 0x28, 0, 16);
    HulkCkptState atentry = {rng, boot, &camptr, clock2, 1}, zeroed = {rng, boot, &camptr, clock0, 0};
    HulkCkptState stale_state = {rng, boot, &camptr, clock2, 0};
    CHECK(hulk_ckpt_hash(7, &atentry) == hulk_ckpt_hash(7, &zeroed) &&
              hulk_ckpt_hash(7, &stale_state) != hulk_ckpt_hash(7, &zeroed),
          "clock_at_entry");
    // a camera singleton that does not exist yet is left out of the hash, as in the hybrid build
    const void* nullcam = 0;
    HulkCkptState early = {rng, boot, &nullcam, clockobj, 0};
    HulkCkptState nocam = {rng, boot, 0, clockobj, 0};
    CHECK(hulk_ckpt_hash(0, &early) != hulk_ckpt_hash(0, &gs) && hulk_ckpt_hash(0, &early) == hulk_ckpt_hash(0, &nocam),
          "null camera");
    // FNV-1a test vector: "a" -> e40c292c, "foobar" -> bf9cf968
    CHECK(hulk_fnv1a(2166136261u, "a", 1) == 0xe40c292cu && hulk_fnv1a(2166136261u, "foobar", 6) == 0xbf9cf968u,
          "fnv vectors");

    // errors: nothing is guessed from a bad file, and a bad HULK_INPUT_SOURCE=replay: does not fall back to pads
    static const char junk[] = "{\"inputs\": [[1, 2";
    CHECK(!hulk_replay_open_memory(junk, sizeof(junk) - 1) && hulk_replay_error()[0], "junk accepted");
    CHECK(!hulk_replay_open_memory("HRP1\x01", 5), "truncated hrp accepted");
    CHECK(!hulk_replay_open_memory("{\"seed\": 1}", 11), "recording without inputs accepted");
    CHECK(!hulk_replay_info(&ri), "info after a failed open");
    hulk_input_shutdown();
    hulk_input_set_source(0);
    SDL_setenv_unsafe("HULK_INPUT_SOURCE", "replay:/nonexistent/recording.json", 1);
    hulk_input_init();
    CHECK(SDL_strcmp(hulk_input_source()->name, "none") == 0 && hulk_input_devices() == 0, "missing file: source %s",
          hulk_input_source()->name);
    hulk_input_shutdown();
    hulk_input_set_source(0);
    // and a good one from the environment, through a file
    const char* out = SDL_getenv("HULK_TEST_OUT");
    char path[512];
    SDL_snprintf(path, sizeof(path), "%s/synth_replay.json", out ? out : ".");
    CHECK(SDL_SaveFile(path, kSynthJson, sizeof(kSynthJson) - 1), "write %s", path);
    char spec[560];
    SDL_snprintf(spec, sizeof(spec), "replay:%s", path);
    SDL_setenv_unsafe("HULK_INPUT_SOURCE", spec, 1);
    hulk_input_init();
    CHECK(SDL_strcmp(hulk_input_source()->name, "replay") == 0 && hulk_input_devices() == 1, "env source: %s",
          hulk_input_source()->name);
    CHECK(stream_hash(25) == 0x7e948749u, "stream through the environment's file");

    // a recording from the machine (never committed): HULK_TEST_REPLAY=<file> [HULK_TEST_REPLAY_POLLS=n] prints the
    // stream hash that `tools/replay_pack.py stream <file> --polls n` must agree with
    const char* real = SDL_getenv("HULK_TEST_REPLAY");
    if (real && *real) {
        const char* np = SDL_getenv("HULK_TEST_REPLAY_POLLS");
        unsigned polls = np ? (unsigned)SDL_strtoul(np, 0, 10) : 100000;
        hulk_input_shutdown();
        hulk_input_set_source(0);
        SDL_snprintf(spec, sizeof(spec), "replay:%s", real);
        SDL_setenv_unsafe("HULK_INPUT_SOURCE", spec, 1);
        hulk_input_init();
        CHECK(SDL_strcmp(hulk_input_source()->name, "replay") == 0, "local recording %s: %s", real,
              hulk_replay_error());
        unsigned h = stream_hash(polls);
        printf("replay-stream %08x polls %u\n", h, polls);
        const char* want = SDL_getenv("HULK_TEST_REPLAY_EXPECT");
        if (want && *want)
            CHECK(h == (unsigned)SDL_strtoul(want, 0, 16), "stream hash %08x vs expected %s", h, want);
    }
    SDL_unsetenv_unsafe("HULK_INPUT_SOURCE");
    hulk_input_shutdown();
    hulk_input_set_source(0);
    hulk_replay_close();
}

int test_main(void)
{
    // units: SDL's ranges -> the Xbox's
    CHECK(hulk_input_trigger(0) == 0 && hulk_input_trigger(32767) == 255 && hulk_input_trigger(16384) == 128 &&
              hulk_input_trigger(-5) == 0,
          "trigger mapping %d %d %d", hulk_input_trigger(0), hulk_input_trigger(32767), hulk_input_trigger(16384));
    CHECK(hulk_input_thumb_y(-32768) == 32767 && hulk_input_thumb_y(32767) == -32767 && hulk_input_thumb_y(0) == 0 &&
              hulk_input_thumb_y(1000) == -1000,
          "thumb y");

    SDL_SetHint(SDL_HINT_JOYSTICK_HIDAPI, "0");         // only our virtual pads (no host pads in the way)
    SDL_SetHint(SDL_HINT_JOYSTICK_RAWINPUT, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_DIRECTINPUT, "0");
    SDL_SetHint(SDL_HINT_XINPUT_ENABLED, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_MFI, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_IOKIT, "0");
    api_init();
    unsigned ins = 0, rem = 0;
    int any = changes(&ins, &rem);
    CHECK(!any && ins == 0 && rem == 0 && devices() == 0, "no pads at start: %d %x %x %x", any, ins, rem, devices());
    CHECK(open_port(0) == 0, "open without a pad");

    // plug in: the next device check reports port 0 inserted (the game opens pads only from it)
    SDL_JoystickID id = attach(0);
    SDL_Joystick* joy = SDL_OpenJoystick(id);
    any = changes(&ins, &rem);
    CHECK(any && ins == 1 && rem == 0 && devices() == 1, "insert: %d %x %x %x", any, ins, rem, devices());
    any = changes(&ins, &rem);
    CHECK(!any && ins == 0 && rem == 0, "reported once: %x %x", ins, rem);
    H h = open_port(0);
    CHECK(h != 0, "open port 0");

    unsigned packet = 0, p0;
    HulkPadState s;
    CHECK(get_state(h, &p0, &s) == 0 && s.buttons == 0 && s.thumb[0] == 0, "idle pad: buttons %x", s.buttons);

    // every input of the Xbox pad
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_SOUTH, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_NORTH, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, true);      // Black
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_DPAD_UP, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_DPAD_RIGHT, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_START, true);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_RIGHT_STICK, true);
    // (a virtual pad's trigger axes span -32768..32767, which SDL's gamepad layer maps to 0..32767: 0 is 16383, 127 of 255)
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFT_TRIGGER, 0);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER, 32767);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFTX, 32767);
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_LEFTY, -32768);     // stick pushed up
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_RIGHTX, -12345);    // right stick left: stays negative
    SDL_SetJoystickVirtualAxis(joy, SDL_GAMEPAD_AXIS_RIGHTY, 1000);      // slightly down
    settle();
    unsigned rc = get_state(h, &packet, &s);
    printf("state: rc %u packet %u buttons 0x%02x analog %u %u %u %u %u %u %u %u thumbs %d %d %d %d\n", rc, packet,
           s.buttons, s.analog[0], s.analog[1], s.analog[2], s.analog[3], s.analog[4], s.analog[5], s.analog[6],
           s.analog[7], s.thumb[0], s.thumb[1], s.thumb[2], s.thumb[3]);
    CHECK(rc == 0 && packet == p0 + 1, "packet %u -> %u", p0, packet);
    CHECK(s.buttons == (HULK_PAD_DPAD_UP | HULK_PAD_DPAD_RIGHT | HULK_PAD_START | HULK_PAD_RIGHT_THUMB),
          "buttons 0x%x", s.buttons);
    CHECK(s.analog[HULK_PAD_A] == 255 && s.analog[HULK_PAD_B] == 0 && s.analog[HULK_PAD_X] == 0 &&
              s.analog[HULK_PAD_Y] == 255 && s.analog[HULK_PAD_BLACK] == 255 && s.analog[HULK_PAD_WHITE] == 0,
          "analog buttons");
    CHECK(s.analog[HULK_PAD_LEFT_TRIGGER] == 127 && s.analog[HULK_PAD_RIGHT_TRIGGER] == 255, "triggers %u %u",
          s.analog[6], s.analog[7]);
    CHECK(s.thumb[HULK_THUMB_LX] == 32767 && s.thumb[HULK_THUMB_LY] == 32767 && s.thumb[HULK_THUMB_RX] == -12345 &&
              s.thumb[HULK_THUMB_RY] == -1000,
          "thumbs %d %d %d %d", s.thumb[0], s.thumb[1], s.thumb[2], s.thumb[3]);

    // the packet number moves only when the state does
    settle();
    unsigned packet2;
    get_state(h, &packet2, &s);
    CHECK(packet2 == packet, "packet moved without a change: %u -> %u", packet, packet2);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_SOUTH, false);
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, true);       // White
    SDL_SetJoystickVirtualButton(joy, SDL_GAMEPAD_BUTTON_BACK, true);
    settle();
    get_state(h, &packet2, &s);
    CHECK(packet2 == packet + 1 && s.analog[HULK_PAD_A] == 0 && s.analog[HULK_PAD_WHITE] == 255 &&
              (s.buttons & HULK_PAD_BACK),
          "change: packet %u A %u White %u buttons %x", packet2, s.analog[0], s.analog[5], s.buttons);

    // rumble: the game's motor words reach the pad (left = low frequency); the request completes at once
    unsigned status = set_rumble(h, 0x8000, 0x4000);
    settle();
    SDL_UpdateGamepads();
    printf("rumble: %d calls, low 0x%04x high 0x%04x, feedback status %u\n", g_rumble[0].calls, g_rumble[0].low,
           g_rumble[0].high, status);
    CHECK(g_rumble[0].calls >= 1 && g_rumble[0].low == 0x8000 && g_rumble[0].high == 0x4000, "rumble %d %x %x",
          g_rumble[0].calls, g_rumble[0].low, g_rumble[0].high);
    CHECK(status == 0, "feedback status %u (the game waits while it reads 997)", status);
    set_rumble(h, 0, 0);
    CHECK(g_rumble[0].low == 0 && g_rumble[0].high == 0, "rumble off");

    // a second pad takes port 1
    SDL_JoystickID id2 = attach(1);
    any = changes(&ins, &rem);
    CHECK(any && ins == 2 && rem == 0 && devices() == 3, "second pad: %x %x %x", ins, rem, devices());

    // unplug pad 1: removed, its handle fails; plug it back: inserted again, a new handle works
    SDL_CloseJoystick(joy);
    SDL_DetachVirtualJoystick(id);
    any = changes(&ins, &rem);
    CHECK(any && ins == 0 && rem == 1 && devices() == 2, "unplug: %x %x %x", ins, rem, devices());
    CHECK(get_state(h, &packet, &s) == 1167, "a removed pad reads ERROR_DEVICE_NOT_CONNECTED");
    close_h(h);
    id = attach(0);
    any = changes(&ins, &rem);
    CHECK(any && ins == 1 && rem == 0 && devices() == 3, "replug: %x %x %x", ins, rem, devices());
    H h2 = open_port(0);
    CHECK(h2 != 0 && get_state(h2, &packet, &s) == 0, "the replugged pad reads");

    // unplug and replug between two device checks: reported as removed and inserted (a new pad in that port)
    SDL_DetachVirtualJoystick(id);
    SDL_UpdateGamepads();
    id = attach(0);
    any = changes(&ins, &rem);
    CHECK(any && ins == 1 && rem == 1, "swap between checks: %x %x", ins, rem);
    CHECK(get_state(h2, &packet, &s) == 1167, "the old handle of a swapped port fails");
    close_h(h2);

#ifdef HULK_TEST_XDK
    // memory units: none
    hulk_u32 mi = 0xdead, mr = 0xdead;
    CHECK(hulk_xdk_XGetDevices(TEST_PTR(hulk_lib_xpp_mu_type)) == 0 && hulk_xdk_XGetDeviceChanges(0x3ea820, TEST_PTR(&mi), TEST_PTR(&mr)) == 0 &&
              mi == 0 && mr == 0,
          "memory units");
    CHECK(hulk_xdk_XGetDevices(0x3ea774) == 3, "the gamepad type by its XBE address");
#endif
    SDL_DetachVirtualJoystick(id);
    SDL_DetachVirtualJoystick(id2);
    hulk_input_shutdown();
    replay_checks();
#ifdef HULK_TEST_XDK
    return test_done("native_input (xdk, i686)");
#else
    return test_done("native_input (host)");
#endif
}
