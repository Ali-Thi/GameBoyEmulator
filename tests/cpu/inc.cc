#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, INC_B_FROM_0_TO_1)
{
    cpu.inc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::B), 1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, INC_B_FROM_4_TO_5)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.inc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::B), 5);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, INC_A_FROM_4_TO_5)
{
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.inc(CPU::ArithmeticR8::A);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 5);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, INC_OVERFLOW)
{
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.inc(CPU::ArithmeticR8::A);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK | HALF_CARRY_FLAG_BYTE_MASK | CARRY_FLAG_BYTE_MASK);
}