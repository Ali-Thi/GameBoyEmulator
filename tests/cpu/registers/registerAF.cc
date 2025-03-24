#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_AF_TO_0)
{
    cpu.set16byteRegister(CPU::R16::AF, 0);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 0);
}

TEST_F(CPUTest, SET_AF_TO_1)
{
    cpu.set16byteRegister(CPU::R16::AF, 1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 0);
}

TEST_F(CPUTest, SET_AF_TO_MINUS_1)
{
    cpu.set16byteRegister(CPU::R16::AF, -1);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 65520);
}

TEST_F(CPUTest, SET_AF_TO_MAX_INT_8_BYTES)
{
    cpu.set16byteRegister(CPU::R16::AF, 255);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 240);
}

TEST_F(CPUTest, SET_AF_TO_MAX_INT_8_BYTES_PLUS_1)
{
    cpu.set16byteRegister(CPU::R16::AF, 256);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 256);
}

TEST_F(CPUTest, SET_AF_TO_MAX_INT_16_BYTES)
{
    cpu.set16byteRegister(CPU::R16::AF, 65535);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 65520);
}

TEST_F(CPUTest, SET_AF_TO_MINUS_12)
{
    cpu.set16byteRegister(CPU::R16::AF, -12);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 65520);
}

TEST_F(CPUTest, SET_AF_TO_MINUS_30)
{
    cpu.set16byteRegister(CPU::R16::AF, -30);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 65504);
}

TEST_F(CPUTest, SET_F)
{
    cpu.set8byteRegister(CPU::R8::F, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 16);
}

TEST_F(CPUTest, SET_A)
{
    cpu.set8byteRegister(CPU::R8::A, 16);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::AF), 4096);
}