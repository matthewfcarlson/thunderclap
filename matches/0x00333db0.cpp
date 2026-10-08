class PlayerBink { public: char pad[0x18]; int state; int value; void vfunc_9(); };
extern void __stdcall FUN_00366b40(int, int);
void PlayerBink::vfunc_9() {
    if (state == 4) { FUN_00366b40(value, 1); state = 3; return; }
    if (state == 2) state = 1;
}