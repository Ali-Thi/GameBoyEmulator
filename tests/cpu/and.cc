#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, AND_0)
{
    cpu.andOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
}

TEST_F(CPUTest, AND_1_255)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.andOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 1);
}

TEST_F(CPUTest, AND_2_4)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 2);
    cpu.andOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
}

TEST_F(CPUTest, AND_INT_TO_INT)
{
    cpu.set8byteRegister(CPU::R8::B, 172);
    cpu.set8byteRegister(CPU::R8::A, 84);
    cpu.andOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 4);
}