#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, ADDHL_0)
{
    cpu.addhl(CPU::R16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 128);
}

TEST_F(CPUTest, ADDHL_INTEGER)
{
    cpu.set16byteRegister(CPU::R16::BC, 4);
    cpu.addhl(CPU::R16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 4);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADDHL_INTEGER_TO_INTEGER)
{
    cpu.set16byteRegister(CPU::R16::BC, 4);
    cpu.set16byteRegister(CPU::R16::HL, 4);
    cpu.addhl(CPU::R16::BC);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 8);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADDHL_AF)
{
    cpu.set16byteRegister(CPU::R16::AF, 16);
    cpu.addhl(CPU::R16::AF);
    EXPECT_EQ(cpu.get16byteRegister(CPU::R16::HL), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 16);
}