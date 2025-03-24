#pragma once

#include <cstdint>

#include "registers.hh"

namespace CPU
{
    class CPU
    {
    public:
        uint8_t get8byteRegister(R8 reg) const;
        void set8byteRegister(R8 reg, uint8_t value);
        uint16_t get16byteRegister(R16 reg) const;
        void set16byteRegister(R16 reg, uint16_t value);

        /**
         * add a register to the A register
         * @param reg the register to add
         */
        void add(R8 reg);

        /**
         * add a register to the HL register
         * @param reg the register to add
         */
        void addhl(R16 reg);

        /**
         * add a register to the A register and add the carry flag is also added to the result
         * @param reg the register to add
         */
        void addc(R8 reg);

    private:
        static std::size_t findRegisterIndex(R8 reg);
        static std::size_t findRegisterIndex(R16 reg);
        /* REPRESENTATION ORDER IN MEMORY : [ A | F | B | C | D | E | H | L ] */
        uint8_t registers[NB_REGISTER] = {};
    };
}