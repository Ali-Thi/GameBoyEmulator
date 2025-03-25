#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, XOR_0)
{
    cpu.xorOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
}

TEST_F(CPUTest, XOR_1_255)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.xorOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 254);
}

TEST_F(CPUTest, XOR_2_4)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 2);
    cpu.xorOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 6);
}

TEST_F(CPUTest, XOR_INT_TO_INT)
{
    cpu.set8byteRegister(CPU::R8::B, 172);
    cpu.set8byteRegister(CPU::R8::A, 84);
    cpu.xorOperator(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 248);
}