#include "cpu.hh"

#include <stdexcept>

namespace CPU
{
    static std::size_t findRegisterIndex(R8 reg);
    static std::size_t findRegisterIndex(R16 reg);
    static R8 arithmeticR8ToR8(ArithmeticR8 reg);
    static R16 arithmeticR16ToR16(ArithmeticR16 reg);

    void CPU::inc(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        uint8_t result;

        setFRegister(__builtin_add_overflow(1, valueReg, &result), 1, valueReg, result);

        set8byteRegister(arithmeticR8ToR8(reg), result);
    }

    void CPU::dec(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        uint8_t result;

        setFRegister(__builtin_sub_overflow(1, valueReg, &result), 1, valueReg, result, true);

        set8byteRegister(arithmeticR8ToR8(reg), result);
    }

    void CPU::cp(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        auto valueAReg = get8byteRegister(R8::A);
        uint8_t result;

        setFRegister(__builtin_sub_overflow(valueAReg, valueReg, &result), valueAReg, valueReg, result, true);
    }

    void CPU::andOperator(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        auto valueAReg = get8byteRegister(R8::A);
        uint8_t result = valueReg & valueAReg;

        setFRegister(false, valueAReg, valueReg, result);

        set8byteRegister(R8::A, result);
    }

    void CPU::orOperator(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        auto valueAReg = get8byteRegister(R8::A);
        uint8_t result = valueReg | valueAReg;

        setFRegister(false, valueAReg, valueReg, result);

        set8byteRegister(R8::A, result);
    }

    void CPU::xorOperator(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        auto valueAReg = get8byteRegister(R8::A);
        uint8_t result = valueReg ^ valueAReg;

        setFRegister(false, valueAReg, valueReg, result);

        set8byteRegister(R8::A, result);
    }

    void CPU::sub(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        auto valueAReg = get8byteRegister(R8::A);
        uint8_t result;

        setFRegister(__builtin_sub_overflow(valueAReg, valueReg, &result), valueAReg, valueReg, result, true);

        set8byteRegister(R8::A, result);
    }

    void CPU::sbc(ArithmeticR8 reg)
    {
        sub(reg);
        auto result = get8byteRegister(R8::A);
        auto valueFReg = get8byteRegister(R8::F);
        __builtin_sub_overflow(result, valueFReg, &result);

        set8byteRegister(R8::A, result);
    }

    void CPU::add(ArithmeticR8 reg)
    {
        auto valueReg = get8byteRegister(arithmeticR8ToR8(reg));
        auto valueAReg = get8byteRegister(R8::A);
        uint8_t result;

        setFRegister(__builtin_add_overflow(valueAReg, valueReg, &result), valueAReg, valueReg, result);

        set8byteRegister(R8::A, result);
    }

    void CPU::addhl(ArithmeticR16 reg)
    {
        auto valueReg = get16byteRegister(arithmeticR16ToR16(reg));
        auto valueHLReg = get16byteRegister(R16::HL);
        uint16_t result;

        setFRegister(__builtin_add_overflow(valueHLReg, valueReg, &result), valueHLReg, valueReg, result);

        set16byteRegister(R16::HL, result);
    }

    void CPU::adc(ArithmeticR8 reg)
    {
        add(reg);
        auto result = get8byteRegister(R8::A);
        auto valueFReg = get8byteRegister(R8::F);
        __builtin_add_overflow(result, valueFReg, &result);

        set8byteRegister(R8::A, result);
    }

    uint8_t CPU::get8byteRegister(R8 reg) const
    {
        return registers[findRegisterIndex(reg)];
    }

    void CPU::set8byteRegister(R8 reg, uint8_t value)
    {
        if (reg == R8::F)
            value = (value & UPPER_NIBBLE);

        registers[findRegisterIndex(reg)] = value;
    }

    uint16_t CPU::get16byteRegister(R16 reg) const
    {
        auto index = findRegisterIndex(reg);
        return (registers[index] << REGISTER_SIZE) + registers[index + 1];
    }

    void CPU::set16byteRegister(R16 reg, uint16_t value)
    {
        auto index = findRegisterIndex(reg);
        registers[index] = ((value & (BYTE_MASK << REGISTER_SIZE)) >> REGISTER_SIZE);

        if (reg == R16::AF)
            registers[index + 1] = (value & UPPER_NIBBLE);
        else
            registers[index + 1] = (value & BYTE_MASK);
    }

    static std::size_t findRegisterIndex(R8 reg)
    {
        switch (reg)
        {
        case R8::A:
            return 0;
        case R8::F:
            return 1;
        case R8::B:
            return 2;
        case R8::C:
            return 3;
        case R8::D:
            return 4;
        case R8::E:
            return 5;
        case R8::H:
            return 6;
        case R8::L:
            return 7;
        }

        throw std::invalid_argument("8 bit register not recognised");
    }

    static std::size_t findRegisterIndex(R16 reg)
    {
        switch (reg)
        {
        case R16::AF:
            return 0;
        case R16::BC:
            return 2;
        case R16::DE:
            return 4;
        case R16::HL:
            return 6;
        }

        throw std::invalid_argument("16 bit register not recognised");
    }

    static R8 arithmeticR8ToR8(ArithmeticR8 reg)
    {
        switch (reg)
        {
        case ArithmeticR8::A:
            return R8::A;
        case ArithmeticR8::B:
            return R8::B;
        case ArithmeticR8::C:
            return R8::C;
        case ArithmeticR8::D:
            return R8::D;
        case ArithmeticR8::E:
            return R8::E;
        case ArithmeticR8::H:
            return R8::H;
        case ArithmeticR8::L:
            return R8::L;
        }

        throw std::invalid_argument("Arithmetic 8 bit register not recognised");
    }

    static R16 arithmeticR16ToR16(ArithmeticR16 reg)
    {
        switch (reg)
        {
        case ArithmeticR16::BC:
            return R16::BC;
        case ArithmeticR16::DE:
            return R16::DE;
        case ArithmeticR16::HL:
            return R16::HL;
        }

        throw std::invalid_argument("Arithmetic 16 bit register not recognised");
    }

    void CPU::setFRegister(bool overflow, uint8_t valueFirstRegister, uint8_t valueLastRegister, const uint8_t &result, bool isSubstraction)
    {
        setFRegister(overflow, static_cast<uint16_t>(valueFirstRegister), static_cast<uint16_t>(valueLastRegister), static_cast<uint16_t>(result), isSubstraction);
    }

    void CPU::setFRegister(bool overflow, uint16_t valueFirstRegister, uint16_t valueLastRegister, const uint16_t &result, bool isSubstraction)
    {
        uint8_t valueFReg = 0;
        if (overflow)
            valueFReg |= CARRY_FLAG_BYTE_MASK;

        if (result == 0)
            valueFReg |= ZERO_FLAG_BYTE_MASK;

        if (!isSubstraction)
        {
            if ((valueFirstRegister & LOWER_NIBBLE) + (valueLastRegister & LOWER_NIBBLE) > LOWER_NIBBLE)
                valueFReg |= HALF_CARRY_FLAG_BYTE_MASK;
        }
        else
        {
            valueFReg |= SUBTRACT_FLAG_BYTE_MASK;

            if ((valueFirstRegister & LOWER_NIBBLE) - (valueLastRegister & LOWER_NIBBLE) > LOWER_NIBBLE)
                valueFReg |= HALF_CARRY_FLAG_BYTE_MASK;
        }

        set8byteRegister(R8::F, valueFReg);
    }
}