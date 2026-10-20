struct Triple {
    unsigned int a, b, c;
};
Triple* __cdecl FUN_002e5410(Triple* destination, int count, const Triple* source) {
    while (count) {
        if (destination)
            *destination = *source;
        ++destination;
        --count;
    }
    return destination;
}