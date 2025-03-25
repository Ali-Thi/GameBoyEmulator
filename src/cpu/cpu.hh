#pragma once

#include <cstdint>

#include "registers.hh"

namespace CPU
{
    class CPU
    {
    public:
        [[nodiscard]] uint8_t get8byteRegister(R8 reg) const;
        void set8byteRegister(R8 reg, uint8_t value);
        [[nodiscard]] uint16_t get16byteRegister(R16 reg) const;
        void set16byteRegister(R16 reg, uint16_t value);

        /**
         * add a register to the A register
         * @param reg the register to add
         */
        void add(ArithmeticR8 reg);

        /**
         * add a register to the HL register
         * @param reg the register to add
         */
        void addhl(ArithmeticR16 reg);

        /**
         * add a register to the A register and also add the carry flag to the result
         * @param reg the register to add
         */
        void adc(ArithmeticR8 reg);

    private:
        /* REPRESENTATION ORDER IN MEMORY : [ A | F | B | C | D | E | H | L ] */
        uint8_t registers[NB_REGISTER] = {};
    };
}