extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" int __cdecl strncmp(const char*, const char*, unsigned int);

struct Path {
  char data[0x48];
  void FUN_001ef320();
  void FUN_001ef370(const char*);
  void FUN_001ef350();
};
struct Screen {
  void FUN_001f4610(int, int, int);
  void FUN_001f47b0(int);
  void FUN_001f46a0();
};
struct Panel {
  Screen* screen;
  void FUN_001efe20(Path*, int, const char*, float);
};
struct Ctx { const char* FUN_0008a2f0(); };
struct Env { Ctx* FUN_00086310(); };
struct Menu {
  Panel* panel;
  Env* env;
  unsigned char enabled;
  unsigned char shown;
  void FUN_001ec480(const char* name, const char* target);
};

void Menu::FUN_001ec480(const char* name, const char* target) {
  Path path;
  path.FUN_001ef320();
  path.FUN_001ef370("Objects");
  path.FUN_001ef370("FE");
  path.FUN_001ef370(name);
  if (enabled)
    panel->FUN_001efe20(&path, 0, target, 100.0f);

  if (!strcmp(name, "pause") || !strcmp(name, "location_map") || !strcmp(name, "mission_objectives") ||
      !strcmp(name, "mission_success") || !strcmp(name, "mission_fail") ||
      !strcmp(name, "story_mission_success") || !strcmp(name, "story_mission_fail") ||
      !strcmp(name, "side_mission_success") || !strcmp(name, "side_mission_fail") ||
      !strcmp(name, "move_gallery")) {
    if (!shown) {
      if (!strcmp(target, "FE_screen_enter_start")) {
        if (!strcmp(name, "mission_success") || !strcmp(name, "story_mission_success") ||
            !strcmp(name, "side_mission_success"))
          FUN_001ec480("success", "success");
        shown = 1;
        panel->screen->FUN_001f4610(1, 1, 1);
      }
    } else if (!strcmp(target, "FE_back")) {
      shown = 0;
      panel->screen->FUN_001f46a0();
    }
  } else if (!strcmp(name, "jump_marker_select") || !strcmp(name, "fullscreen_message")) {
    if (!shown) {
      if (!strcmp(target, "FE_screen_enter_start")) {
        FUN_001ec480("success", "success");
        shown = 1;
        panel->screen->FUN_001f4610(1, 0, 0);
      } else if (!strcmp(target, "c07m02")) {
        FUN_001ec480("Briefings", target);
        panel->screen->FUN_001f4610(0, 1, 1);
        shown = 1;
      }
    } else if (!strcmp(target, "FE_back")) {
      shown = 0;
      panel->screen->FUN_001f46a0();
      panel->screen->FUN_001f47b0(0);
    }
  } else if (!strcmp(name, "mission_accept")) {
    if (!strcmp(target, "FE_screen_enter_start")) {
      shown = 1;
      panel->screen->FUN_001f4610(0, 1, 1);
      FUN_001ec480("Briefings", env->FUN_00086310()->FUN_0008a2f0());
    }
    if (!strcmp(target, "FE_back")) {
      panel->screen->FUN_001f47b0(0);
      shown = 0;
      panel->screen->FUN_001f46a0();
    }
  } else if (!strcmp(name, "blonsky_file") || !strcmp(name, "mission_briefing")) {
    if (!strncmp(target, "bf", 2)) {
      panel->screen->FUN_001f4610(0, 1, 1);
      shown = 1;
    } else if (!strcmp(target, "FE_back")) {
      panel->screen->FUN_001f47b0(0);
      if (shown) {
        shown = 0;
        panel->screen->FUN_001f46a0();
      }
    }
  }
  path.FUN_001ef350();
}
