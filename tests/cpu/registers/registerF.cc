#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_F_TO_0)
{
    cpu.set8byteRegister(CPU::R8::F, 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, SET_F_TO_1)
{
    cpu.set8byteRegister(CPU::R8::F, 1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, SET_F_TO_MINUS_1)
{
    cpu.set8byteRegister(CPU::R8::F, -1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 240);
}

TEST_F(CPUTest, SET_F_TO_MAX_INT_8_BYTES)
{
    cpu.set8byteRegister(CPU::R8::F, 255);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 240);
}

TEST_F(CPUTest, SET_F_TO_MINUS_12)
{
    cpu.set8byteRegister(CPU::R8::F, -12);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 240);
}