#include "cputest.hh"

#include <gtest/gtest.h>
#include <cpu.hh>


TEST_F(CPUTest, ADC_0)
{
    cpu.adc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 128);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 128);
}

TEST_F(CPUTest, ADC_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.adc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 4);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADC_INTEGER_TO_INTEGER)
{
    cpu.set8byteRegister(CPU::R8::B, 4);
    cpu.set8byteRegister(CPU::R8::A, 4);
    cpu.adc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 8);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 0);
}

TEST_F(CPUTest, ADC_OVERFLOW)
 {
    cpu.set8byteRegister(CPU::R8::B, 1);
    cpu.set8byteRegister(CPU::R8::A, 255);
    cpu.adc(CPU::ArithmeticR8::B);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::A), 176);
    EXPECT_EQ(cpu.get8byteRegister(CPU::R8::F), 176);
}