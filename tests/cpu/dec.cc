#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, DEC_B_FROM_1_TO_0)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.dec(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::B), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 128);
}

TEST_F(CPUTest, DEC_B_FROM_4_TO_3)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.dec(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::B), 3);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, DEC_A_FROM_4_TO_3)
{
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.dec(CPU::ArithmeticR8::A);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 3);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, DEC_OVERFLOW)
{
    cpu.set8byteRegister(CPU::R8::A, 0);
    cpu.dec(CPU::ArithmeticR8::A);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 255);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 176);
}