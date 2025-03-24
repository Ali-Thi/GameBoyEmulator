#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_BC_TO_0)
{
    cpu.set16byteRegister(CPU::R16::BC, 0);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 0);
}

TEST_F(CPUTest, SET_BC_TO_1)
{
    cpu.set16byteRegister(CPU::R16::BC, 1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 1);
}

TEST_F(CPUTest, SET_BC_TO_MINUS_1)
{
    cpu.set16byteRegister(CPU::R16::BC, -1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 65535);
}

TEST_F(CPUTest, SET_BC_TO_MAX_INT_8_BYTES)
{
    cpu.set16byteRegister(CPU::R16::BC, 255);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 255);
}

TEST_F(CPUTest, SET_BC_TO_MAX_INT_8_BYTES_PLUS_1)
{
    cpu.set16byteRegister(CPU::R16::BC, 256);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 256);
}

TEST_F(CPUTest, SET_BC_TO_MAX_INT_16_BYTES)
{
    cpu.set16byteRegister(CPU::R16::BC, 65535);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 65535);
}

TEST_F(CPUTest, SET_BC_TO_MINUS_12)
{
    cpu.set16byteRegister(CPU::R16::BC, -12);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 65524);
}

TEST_F(CPUTest, SET_C)
{
    cpu.set8byteRegister(CPU::R8::C, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 16);
}

TEST_F(CPUTest, SET_B)
{
    cpu.set8byteRegister(CPU::R8::B, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::BC), 4096);
}