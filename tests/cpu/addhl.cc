#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, ADDHL_0)
{
    cpu.addhl(CPU::ArithmeticR16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK);
}

TEST_F(CPUTest, ADDHL_INTEGER)
{
    cpu.set16byteRegister(CPU::R16::BC, 4);
    cpu.addhl(CPU::ArithmeticR16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 4);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADDHL_INTEGER_TO_INTEGER)
{
    cpu.set16byteRegister(CPU::R16::BC, 4);
    cpu.set16byteRegister(CPU::R16::HL, 4);
    cpu.addhl(CPU::ArithmeticR16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 8);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADDHL_OVERFLOW)
{
    cpu.set16byteRegister(CPU::R16::BC, 1);
    cpu.set16byteRegister(CPU::R16::HL, 65535);
    cpu.addhl(CPU::ArithmeticR16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK | HALF_CARRY_FLAG_BYTE_MASK | CARRY_FLAG_BYTE_MASK);
}