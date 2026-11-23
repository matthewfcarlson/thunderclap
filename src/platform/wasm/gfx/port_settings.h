/* The port's settings and the remastered-edition switch (D232, D233; docs/wasm-port.md "Settings and the remastered
 * edition"; HULK_WASM_GFX=1 builds only).
 *
 * One table (port_settings.c) lists every setting the port adds: its key in HULK_SAVE_DIR/port_settings.txt, the
 * screen and label of its menu item (fe_options.c builds the items from the table), its kind and choices, its faithful
 * value (the original's behaviour) and its remastered default, and the function that applies it. Values are ints (a
 * choice's value, not its index). The app is the remastered edition (hulk_remastered_build): with the switch on
 * (`remastered`, Gameplay Options) every setting takes the player's value, the remastered default until they change
 * it; with it off every remastered-only setting takes its faithful value, and the player's values come back when it
 * is turned on again. Runs that test or replay (a recording, HULK_INPUT, HULK_ROLLTEST) never read or write the file
 * and start from the faithful values; HULK_SETTINGS="key=value,..." pins values in any run. */
#ifndef HULK_PORT_SETTINGS_H
#define HULK_PORT_SETTINGS_H

enum { PS_CHOICE, PS_ONOFF, PS_SLIDER };          /* how the item shows (a slider: an ordered choice of numbers) */
enum { PS_SCREEN_VIDEO, PS_SCREEN_GAMEPLAY, PS_SCREENS, PS_SCREEN_NONE = -1 };   /* NONE: in the file only */
enum { PS_MAX_CHOICES = 12 };

typedef struct port_setting {
    const char* key;            /* the file's key; the menu's string ids derive from it (TBS_PORT_<KEY>[_<choice>]);
                                   "dev_<name>": a developer row (wdev1), listed and in effect only in developer mode,
                                   else its faithful value */
    const char* label;          /* the item's text (English; the port's own string) */
    int screen;                 /* PS_SCREEN_* */
    int kind;                   /* PS_* */
    int n;                      /* choices */
    int values[PS_MAX_CHOICES];
    const char* names[PS_MAX_CHOICES];
    int faithful;               /* the original's behaviour (a value of `values`) */
    int remastered;             /* the remastered edition's default */
    int remastered_only;        /* 1: the faithful value whenever the edition switch is off */
    void (*apply)(int value);   /* the effective value changed (also called once at load); may be 0 */
} port_setting;

int hulk_remastered_build(void);                  /* 1: this build is the remastered edition (the app) */
int hulk_remastered(void);                        /* the edition switch: remastered behaviour on */
int hulk_setting(const char* key);                /* the effective value (faithful when the switch is off) */
int hulk_setting_user(int i);                     /* setting i's chosen value (what its item shows when allowed) */
void hulk_setting_choose(int i, int value);       /* the player chose (the menu): store, save, apply */
int hulk_settings_count(void);
const port_setting* hulk_settings_at(int i);
int hulk_settings_find(const char* key);          /* the index, or -1 */
int hulk_setting_index(const port_setting* s, int value);   /* the choice index of a value (0 when not listed) */
int hulk_setting_locked(int i);                   /* 1: the item shows its faithful value and refuses changes */
int hulk_setting_listed(int i);                   /* 1: setting i has a menu item (its screen; developer rows only in
                                                     developer mode) */
int hulk_developer_mode(void);                    /* developer=1 in the file or HULK_DEV=1 (wdev1) */
void hulk_settings_load(void);                    /* once; every accessor calls it */

#endif
