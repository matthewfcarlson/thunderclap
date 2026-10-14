void FUN_003641c0();
extern "C" int __cdecl _atexit(void(__cdecl* f)());

void Register() {
    _atexit(FUN_003641c0);
}
