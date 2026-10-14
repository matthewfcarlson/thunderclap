struct Obj34 {
    int GetCount();
    void Reset();
};
struct Dlg_bf1e0 {
    void Init();
};
struct Game_bf1e0 {
    char pad0[0x10];
    int state;
    char pad14[0x1c];
    int member30;
    Obj34* o34;
    char pad38[0x1cc0];
    int value1cf8;
    void Use(int);
    void Finish();
    void Run();
};
extern char gZero_bf1e0;
extern Dlg_bf1e0* __stdcall CreateDialog(const char*, const char*, const void*, const char*, const char*, int, int,
                                   int);
extern void __cdecl Show(const char*);
void Game_bf1e0::Run() {
    if (o34) {
        if (o34->GetCount() > 0) {
            if (member30) {
                CreateDialog("FEGenericDialog", "TBS_MENU_ITEM_RESTART_DEMO", &gZero_bf1e0, "TBS_MENU_ITEM_OK",
                             "TBS_CANCEL", 2, 0, 0)
                    ->Init();
                state = 0x12;
                Finish();
            }
        } else {
            o34->Reset();
            Use(value1cf8);
            Show("save_new_game");
        }
    }
}
