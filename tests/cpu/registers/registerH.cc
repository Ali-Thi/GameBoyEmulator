#include "../cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, SET_H_TO_0)
{
    cpu.set8byteRegister(CPU::R8::H, 0);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::H), 0);
}

TEST_F(CPUTest, SET_H_TO_1)
{
    cpu.set8byteRegister(CPU::R8::H, 1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::H), 1);
}

TEST_F(CPUTest, SET_H_TO_MINUS_1)
{
    cpu.set8byteRegister(CPU::R8::H, -1);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::H), 255);
}

TEST_F(CPUTest, SET_H_TO_MAX_INT_8_BYTES)
{
    cpu.set8byteRegister(CPU::R8::H, 255);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::H), 255);
}

TEST_F(CPUTest, SET_H_TO_MINUS_12)
{
    cpu.set8byteRegister(CPU::R8::H, -12);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::H), 244);
}