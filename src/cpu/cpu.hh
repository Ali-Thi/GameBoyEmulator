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
         * @param reg the register
         */
        void add(ArithmeticR8 reg);

        /**
         * add a register to the HL register
         * @param reg the register
         */
        void addhl(ArithmeticR16 reg);

        /**
         * add a register to the A register and also add the carry flag to the result
         * @param reg the register
         */
        void adc(ArithmeticR8 reg);

        /**
         * subtract a register to the A register
         * @param reg the register
         */
        void sub(ArithmeticR8 reg);

        /**
         * subtract a register to the A register and also subtract the carry flag to the result
         * @param reg the register
         */
        void sbc(ArithmeticR8 reg);

        /**
         * do a bitwise and on the value in a specific register and the value in the A register
         * @param reg the register
         */
        void andOperator(ArithmeticR8 reg);

        /**
         * do a bitwise or on the value in a specific register and the value in the A register
         * @param reg the register
         */
        void orOperator(ArithmeticR8 reg);

        /**
         * do a bitwise xor on the value in a specific register and the value in the A register
         * @param reg the register
         */
        void xorOperator(ArithmeticR8 reg);

        /**
         * just like SUB except the result of the subtraction is not stored back into A
         * @param reg the register
         */
        void cp(ArithmeticR8 reg);

        /**
         * increment the value in a specific register by 1
         * @param reg the register
         */
        void inc(ArithmeticR8 reg);

        /**
         * decrement the value in a specific register by 1
         * @param reg the register
         */
        void dec(ArithmeticR8 reg);

        /**
         * toggle the value of the carry flag
         */
        void ccf();

        /*
        SCF (set carry flag) - set the carry flag to true
        RRA (rotate right A register) - bit rotate A register right through the carry flag
        RLA (rotate left A register) - bit rotate A register left through the carry flag
        RRCA (rotate right A register) - bit rotate A register right (not through the carry flag)
        RRLA (rotate left A register) - bit rotate A register left (not through the carry flag)
        CPL (complement) - toggle every bit of the A register
        BIT (bit test) - test to see if a specific bit of a specific register is set
        RESET (bit reset) - set a specific bit of a specific register to 0
        SET (bit set) - set a specific bit of a specific register to 1
        SRL (shift right logical) - bit shift a specific register right by 1
        RR (rotate right) - bit rotate a specific register right by 1 through the carry flag
        RL (rotate left) - bit rotate a specific register left by 1 through the carry flag
        RRC (rorate right) - bit rotate a specific register right by 1 (not through the carry flag)
        RLC (rorate left) - bit rotate a specific register left by 1 (not through the carry flag)
        SRA (shift right arithmetic) - arithmetic shift a specific register right by 1
        SLA (shift left arithmetic) - arithmetic shift a specific register left by 1
        SWAP (swap nibbles) - switch upper and lower nibble of a specific register
         */

    private:
        void setFRegister(bool overflow, uint8_t valueFirstRegister, uint8_t valueLastRegister, const uint8_t &result, bool isSubstraction = false);
        void setFRegister(bool overflow, uint16_t valueFirstRegister, uint16_t valueLastRegister, const uint16_t &result, bool isSubstraction = false);
        // REPRESENTATION ORDER IN MEMORY : [ A | F | B | C | D | E | H | L ]
        uint8_t registers[NB_REGISTER] = {};
    };
}