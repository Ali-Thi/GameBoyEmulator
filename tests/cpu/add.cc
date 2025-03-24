#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, ADD_0)
{
    cpu.add(CPU::R8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 128);
}

TEST_F(CPUTest, ADD_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.add(CPU::R8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 4);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADD_INTEGER_TO_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.add(CPU::R8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 8);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADD_F)
{
    cpu.set8byteRegister(CPU::R8::F, 16);
    cpu.add(CPU::R8::F);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 16);
}