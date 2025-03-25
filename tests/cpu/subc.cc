#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SBC_0)
{
    cpu.sbc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 64);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 192);
}

TEST_F(CPUTest, SBC_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.sbc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 190);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 64);
}

TEST_F(CPUTest, SBC_INTEGER_TO_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.sbc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 64);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 192);
}

TEST_F(CPUTest, SBC_OVERFLOW)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.sbc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 172);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 80);
}