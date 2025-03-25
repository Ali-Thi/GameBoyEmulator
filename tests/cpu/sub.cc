#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SUB_0)
{
    cpu.sub(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 192);
}

TEST_F(CPUTest, SUB_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.sub(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 254);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 64);
}

TEST_F(CPUTest, SUB_INTEGER_TO_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.sub(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 192);
}

TEST_F(CPUTest, SUB_OVERFLOW)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.sub(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 252);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 80);
}