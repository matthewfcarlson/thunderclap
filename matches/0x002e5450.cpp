struct Triple {
    unsigned int first, second, third;
};
Triple* __cdecl FUN_002e5450(Triple* destination, unsigned int count, const Triple* source) {
    for (; count; --count) {
        if (destination)
            *destination = *source;
        destination = (Triple*)((char*)destination + 12);
    }
    return destination;
}