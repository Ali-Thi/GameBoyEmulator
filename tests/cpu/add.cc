#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, ADD_0)
{
    cpu.add(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK);
}

TEST_F(CPUTest, ADD_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.add(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 4);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADD_INTEGER_TO_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.add(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 8);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADD_OVERFLOW)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.add(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), ZERO_FLAG_BYTE_MASK | HALF_CARRY_FLAG_BYTE_MASK | CARRY_FLAG_BYTE_MASK);
}