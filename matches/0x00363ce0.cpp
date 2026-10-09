extern "C" int __cdecl Check();
extern "C" void __cdecl Action();
extern "C" void __cdecl Target() {
    if (Check())
        Action();
}