#pragma once

#define NB_REGISTER 8
#define REGISTER_SIZE 8

#define BYTE_MASK 0b11111111
#define UPPER_NIBBLE 0b11110000
#define LOWER_NIBBLE 0b00001111

#define ZERO_FLAG_BYTE_MASK 128 // Z flag
#define SUBTRACT_FLAG_BYTE_MASK 64 // N flag
#define HALF_CARRY_FLAG_BYTE_MASK 32 // H flag
#define CARRY_FLAG_BYTE_MASK 16 // C flag

namespace CPU
{
    enum class R8
    {
        A,
        B,
        C,
        D,
        E,
        F,
        H,
        L,
    };

    enum class R16
    {
        AF,
        BC,
        DE,
        HL,
    };

    enum class ArithmeticR8
    {
        A,
        B,
        C,
        D,
        E,
        H,
        L,
    };

    enum class ArithmeticR16
    {
        BC,
        DE,
        HL,
    };
}