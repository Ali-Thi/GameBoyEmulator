#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_D_TO_0)
{
    cpu.set8byteRegister(CPU::R8::D, 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::D), 0);
}

TEST_F(CPUTest, SET_D_TO_1)
{
    cpu.set8byteRegister(CPU::R8::D, 1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::D), 1);
}

TEST_F(CPUTest, SET_D_TO_MINUS_1)
{
    cpu.set8byteRegister(CPU::R8::D, -1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::D), 255);
}

TEST_F(CPUTest, SET_D_TO_MAX_INT_8_BYTES)
{
    cpu.set8byteRegister(CPU::R8::D, 255);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::D), 255);
}

TEST_F(CPUTest, SET_D_TO_MINUS_12)
{
    cpu.set8byteRegister(CPU::R8::D, -12);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::D), 244);
}