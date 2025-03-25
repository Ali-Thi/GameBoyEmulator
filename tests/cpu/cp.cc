#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, CP_0)
{
    cpu.cp(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK | SUBTRACT_FLAG_BYTE_MASK);
}

TEST_F(CPUTest, CP_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.cp(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 255);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), SUBTRACT_FLAG_BYTE_MASK);
}

TEST_F(CPUTest, CP_INTEGER_TO_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.cp(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 4);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK | SUBTRACT_FLAG_BYTE_MASK);
}

TEST_F(CPUTest, CP_OVERFLOW)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.cp(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), SUBTRACT_FLAG_BYTE_MASK | CARRY_FLAG_BYTE_MASK);
}