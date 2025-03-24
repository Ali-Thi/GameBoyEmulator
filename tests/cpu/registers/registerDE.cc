#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_DE_TO_0)
{
    cpu.set16byteRegister(CPU::R16::DE, 0);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 0);
}

TEST_F(CPUTest, SET_DE_TO_1)
{
    cpu.set16byteRegister(CPU::R16::DE, 1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 1);
}

TEST_F(CPUTest, SET_DE_TO_MINUS_1)
{
    cpu.set16byteRegister(CPU::R16::DE, -1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 65535);
}

TEST_F(CPUTest, SET_DE_TO_MAX_INT_8_BYTES)
{
    cpu.set16byteRegister(CPU::R16::DE, 255);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 255);
}

TEST_F(CPUTest, SET_DE_TO_MAX_INT_8_BYTES_PLUS_1)
{
    cpu.set16byteRegister(CPU::R16::DE, 256);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 256);
}

TEST_F(CPUTest, SET_DE_TO_MAX_INT_16_BYTES)
{
    cpu.set16byteRegister(CPU::R16::DE, 65535);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 65535);
}

TEST_F(CPUTest, SET_DE_TO_MINUS_12)
{
    cpu.set16byteRegister(CPU::R16::DE, -12);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 65524);
}

TEST_F(CPUTest, SET_E)
{
    cpu.set8byteRegister(CPU::R8::E, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 16);
}

TEST_F(CPUTest, SET_D)
{
    cpu.set8byteRegister(CPU::R8::D, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::DE), 4096);
}