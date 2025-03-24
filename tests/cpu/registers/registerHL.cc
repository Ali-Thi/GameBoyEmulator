#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_HL_TO_0)
{
    cpu.set16byteRegister(CPU::R16::HL, 0);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 0);
}

TEST_F(CPUTest, SET_HL_TO_1)
{
    cpu.set16byteRegister(CPU::R16::HL, 1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 1);
}

TEST_F(CPUTest, SET_HL_TO_MINUS_1)
{
    cpu.set16byteRegister(CPU::R16::HL, -1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 65535);
}

TEST_F(CPUTest, SET_HL_TO_MAX_INT_8_BYTES)
{
    cpu.set16byteRegister(CPU::R16::HL, 255);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 255);
}

TEST_F(CPUTest, SET_HL_TO_MAX_INT_8_BYTES_PLUS_1)
{
    cpu.set16byteRegister(CPU::R16::HL, 256);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 256);
}

TEST_F(CPUTest, SET_HL_TO_MAX_INT_16_BYTES)
{
    cpu.set16byteRegister(CPU::R16::HL, 65535);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 65535);
}

TEST_F(CPUTest, SET_HL_TO_MINUS_12)
{
    cpu.set16byteRegister(CPU::R16::HL, -12);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 65524);
}

TEST_F(CPUTest, SET_L)
{
    cpu.set8byteRegister(CPU::R8::L, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 16);
}

TEST_F(CPUTest, SET_H)
{
    cpu.set8byteRegister(CPU::R8::H, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 4096);
}