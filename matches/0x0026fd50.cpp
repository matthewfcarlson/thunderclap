unsigned int FUN_0026fd50(unsigned int param_1, unsigned int param_2)
{
    if (param_2 != 0 && param_1 % param_2 != 0)
        return (param_1 - param_1 % param_2) + param_2;
    return param_1;
}
