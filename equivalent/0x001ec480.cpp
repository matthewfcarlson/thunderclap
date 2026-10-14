// STATUS: equivalent (tools/equiv.py level 3: 12048 inputs, branch coverage 64/68, incomplete; run with --inputs 12000)
// FUN_001ec480 @ 0x001ec480
extern "C" int __cdecl strncmp(const char*, const char*, unsigned);
struct Path_1ec480 {
    char data[72];
    void FUN_001ef320();
    void FUN_001ef370(const char*);
    void FUN_001ef350();
};
struct Screen_1ec480 {
    void FUN_001f4610(int, int, int);
    void FUN_001f47b0(int);
    void FUN_001f46a0();
};
struct UI_1ec480 {
    Screen_1ec480* screen;
    void FUN_001efe20(Path_1ec480*, int, const char*, float);
};
struct Info_1ec480 { const char* FUN_0008a2f0(); };
struct Owner_1ec480 { Info_1ec480* FUN_00086310(); };
struct Target_1ec480 {
    UI_1ec480* ui;
    Owner_1ec480* owner;
    unsigned char enabled, active;
    void FUN_001ec480(const char*, const char*);
    void run(const char*, const char*);
};
// Compare locally: these comparisons do not call the string library.
#define EQUAL(result, text, literal) \
    do { const char* a = (text); const char* b = (literal); \
         while (*a == *b && *b) { ++a; ++b; } \
         (result) = (*a == *b); } while (0)
void Target_1ec480::run(const char* name, const char* value) {
    Path_1ec480 path;
    path.FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("FE");
    path.FUN_001ef370(name);
    if (enabled) ui->FUN_001efe20(&path, 0, value, 100.0f);

    const char* names[] = {
        "pause", "location_map", "mission_objectives", "mission_success",
        "mission_fail", "story_mission_success", "story_mission_fail",
        "side_mission_success", "side_mission_fail", "move_gallery",
        "jump_marker_select", "fullscreen_message", "mission_accept",
        "blonsky_file", "mission_briefing"
    };
    int kind;
    for (kind = 0; kind < 15; ++kind) {
        bool equal;
        EQUAL(equal, name, names[kind]);
        if (equal) break;
    }
    bool equal;
    if (kind < 10) {
        if (!active) {
            EQUAL(equal, value, "FE_screen_enter_start");
            if (equal) {
                bool success;
                EQUAL(success, name, "mission_success");
                if (!success) EQUAL(success, name, "story_mission_success");
                if (!success) EQUAL(success, name, "side_mission_success");
                if (success) FUN_001ec480("success", "success");
                UI_1ec480* current = ui;
                active = 1;
                current->screen->FUN_001f4610(1, 1, 1);
            }
        } else {
            EQUAL(equal, value, "FE_back");
            if (equal) {
                UI_1ec480* current = ui;
                active = 0;
                current->screen->FUN_001f46a0();
            }
        }
    } else if (kind < 12) {
        if (!active) {
            EQUAL(equal, value, "FE_screen_enter_start");
            if (equal) {
                FUN_001ec480("success", "success");
                UI_1ec480* current = ui;
                active = 1;
                current->screen->FUN_001f4610(1, 0, 0);
            } else {
                EQUAL(equal, value, "c07m02");
                if (equal) {
                    FUN_001ec480("Briefings", value);
                    ui->screen->FUN_001f4610(0, 1, 1);
                    active = 1;
                }
            }
        } else {
            EQUAL(equal, value, "FE_back");
            if (equal) {
                UI_1ec480* current = ui;
                active = 0;
                current->screen->FUN_001f46a0();
                ui->screen->FUN_001f47b0(0);
            }
        }
    } else if (kind == 12) {
        EQUAL(equal, value, "FE_screen_enter_start");
        if (equal) {
            UI_1ec480* current = ui;
            active = 1;
            current->screen->FUN_001f4610(0, 1, 1);
            const char* briefing = owner->FUN_00086310()->FUN_0008a2f0();
            FUN_001ec480("Briefings", briefing);
        }
        EQUAL(equal, value, "FE_back");
        if (equal) {
            ui->screen->FUN_001f47b0(0);
            UI_1ec480* current = ui;
            active = 0;
            current->screen->FUN_001f46a0();
        }
    } else if (kind < 15) {
        if (strncmp(value, "bf", 2) == 0) {
            ui->screen->FUN_001f4610(0, 1, 1);
            active = 1;
        } else {
            EQUAL(equal, value, "FE_back");
            if (equal) {
                ui->screen->FUN_001f47b0(0);
                if (active) {
                    UI_1ec480* current = ui;
                    active = 0;
                    current->screen->FUN_001f46a0();
                }
            }
        }
    }
    path.FUN_001ef350();
}
