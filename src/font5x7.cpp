// MIT License

// Copyright (c) 2022 Chris Sutton

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <font.hpp>

// @brief static member initializations for specialized template classes

namespace ssd1306
{

// Font5x7 is declared in font.hpp

// 5x7 - '1'
// 11 LSB DONT CARE
//
// - - o - - x x x x x x x x x x x	0x2000  ROW #0
// - o o - - x x x x x x x x x x x	0x6000  ROW #1
// o - o - - x x x x x x x x x x x	0xA000  ROW #2
// - - o - - x x x x x x x x x x x	0x2000  ROW #3
// - - o - - x x x x x x x x x x x	0x2000  ROW #4
// - - o - - x x x x x x x x x x x	0x2000  ROW #5
// o o o o o x x x x x x x x x x x	0xFF00  ROW #6

// @brief only 5 MSB of each halfword are used. 1 bit per col.
template <> uint8_t const Font5x7::m_width{5};

// @brief 7 rows of two bytes (half-words)
template <> uint8_t const Font5x7::m_height{font5x7_height};

// @brief The font data, top to bottom.
template <>
std::array<uint16_t, Font5x7::m_height * char_map_size> Font5x7::data{
    // clang-format off
    //  ROW #0  ROW #1  ROW #2  ROW #3  ROW #4  ROW #5  ROW #6
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // sp
    0x1000, 0x1000, 0x1000, 0x1000, 0x0000, 0x1000, 0x0000, // !
    0x5000, 0x5000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // "
    0x0000, 0x5000, 0xFFFF, 0x5000, 0xFFFF, 0x5000, 0x0000, // #
    0x2000, 0x7800, 0xA000, 0x7000, 0x2800, 0xF000, 0x2000, // $
    0x0000, 0x8800, 0x1000, 0x2000, 0x4000, 0x8800, 0x0000, // %
    0x7000, 0x8000, 0xC000, 0x6800, 0xB000, 0x9000, 0x6800, // &
    0x2000, 0x2000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // '
    0x1000, 0x2000, 0x4000, 0x4000, 0x4000, 0x2000, 0x1000, // (
    0x2000, 0x1000, 0x4000, 0x4000, 0x4000, 0x1000, 0x2000, // )
    0x2000, 0xA800, 0x7000, 0x2000, 0x7000, 0xA800, 0x2000, // *
    0x2000, 0x2000, 0x2000, 0xFFFF, 0x2000, 0x2000, 0x2000, // +
    0x0000, 0x0000, 0x0000, 0x0000, 0x2000, 0x2000, 0x4000, // ,
    0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, // -
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2000, // .
    0x0000, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000, 0x0000, // /
    0x7000, 0x8800, 0x9800, 0xA800, 0xC800, 0x8800, 0x7000, // 0
    0x2000, 0x6000, 0xA000, 0x2000, 0x2000, 0x2000, 0xFF00, // 1
    0x7000, 0x8800, 0x0800, 0x1000, 0x2000, 0x4000, 0xFF00, // 2
    0x7000, 0x8800, 0x0800, 0x3000, 0x0800, 0x8800, 0x7000, // 3
    0x1000, 0x3000, 0x5000, 0xFFFF, 0x1000, 0x1000, 0x1000, // 4
    0xFFFF, 0x8000, 0x8000, 0xF000, 0x0800, 0x0800, 0xF000, // 5
    0x7000, 0x8800, 0x8000, 0xF000, 0x8800, 0x8800, 0x7000, // 6
    0xFFFF, 0x0800, 0x1000, 0x2000, 0x2000, 0x2000, 0x2000, // 7
    0x7000, 0x8800, 0x8800, 0x7000, 0x8800, 0x8800, 0x7000, // 8
    0x7000, 0x8800, 0x8800, 0x7800, 0x0800, 0x8800, 0x7000, // 9
    0x0000, 0x0000, 0x2000, 0x0000, 0x2000, 0x0000, 0x0000, // :
    0x0000, 0x0000, 0x2000, 0x0000, 0x2000, 0x4000, 0x0000, // ;
    0x1000, 0x2000, 0x4000, 0x8000, 0x4000, 0x2000, 0x1000, // <
    0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, // =
    0x4000, 0x2000, 0x1000, 0x0800, 0x1000, 0x2000, 0x4000, // >
    0x6000, 0x1000, 0x1000, 0x2000, 0x2000, 0x0000, 0x2000, // ?
    0x7000, 0x8800, 0xB800, 0xA800, 0xB000, 0x8000, 0x7000, // @
    0x2000, 0x5000, 0x8800, 0x8800, 0xFFFF, 0x8800, 0x8800, // A
    0xF000, 0x8800, 0x8800, 0xF000, 0x8800, 0x8800, 0xF000, // B
    0x7800, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x7800, // C
    0xE000, 0x9000, 0x8800, 0x8800, 0x8800, 0x9000, 0xE000, // D
    0xFFFF, 0x8000, 0x8000, 0xFFFF, 0x8000, 0x8000, 0xFFFF, // E
    0xFFFF, 0x8000, 0x8000, 0xE000, 0x8000, 0x8000, 0x8000, // F
    0x7000, 0x8800, 0x8000, 0x8000, 0x9800, 0x8800, 0x7000, // G
    0x8800, 0x8800, 0x8800, 0xFFFF, 0x8800, 0x8800, 0x8800, // H
    0x7000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x7000, // I
    0x7000, 0x1000, 0x1000, 0x1000, 0x1000, 0x9000, 0x6000, // J
    0x8800, 0x9000, 0xA000, 0xC000, 0xA000, 0x9000, 0x8800, // K
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0xFFFF, // L
    0x8800, 0xD800, 0xA800, 0x8800, 0x8800, 0x8800, 0x8800, // M
    0x8800, 0xC800, 0xC800, 0xA800, 0x9800, 0x9800, 0x8800, // N
    0x7000, 0x8800, 0x8800, 0x8800, 0x8800, 0x8800, 0x7000, // O
    0xF000, 0x8800, 0x8800, 0xF000, 0x8000, 0x8000, 0x8000, // P
    0x7000, 0x8800, 0x8800, 0x8800, 0x8800, 0x7000, 0x1800, // Q
    0xF000, 0x8800, 0x8800, 0xF000, 0x9000, 0x8800, 0x8800, // R
    0x7000, 0x8800, 0x8000, 0x7000, 0x0800, 0x8800, 0x7000, // S
    0xFFFF, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, // T
    0x8800, 0x8800, 0x8800, 0x8800, 0x8800, 0x8800, 0x7000, // U
    0x8800, 0x8800, 0x8800, 0x5000, 0x5000, 0x5000, 0x2000, // V
    0x8800, 0x8800, 0x8800, 0x8800, 0xA800, 0xA800, 0x5000, // W
    0x8800, 0x8800, 0x5000, 0x2000, 0x5000, 0x8800, 0x8800, // X
    0x8800, 0x8800, 0x5000, 0x2000, 0x2000, 0x2000, 0x2000, // Y
    0xFFFF, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000, 0xFFFF, // Z
    0x7000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x7000, // [
    0x2000, 0x2000, 0x1000, 0x1000, 0x1000, 0x1000, 0x0800, /* \ */
    0x7000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x7000, // ]
    0x2000, 0x5000, 0x8800, 0x0000, 0x0000, 0x0000, 0x0000, // ^
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // _
    0x2000, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // `
    0x2000, 0x5000, 0x8800, 0x8800, 0xFFFF, 0x8800, 0x8800, // a
    0xF000, 0x8800, 0x8800, 0xF000, 0x8800, 0x8800, 0xF000, // b
    0x7800, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x7800, // c
    0xE000, 0x9000, 0x8800, 0x8800, 0x8800, 0x9000, 0xE000, // d
    0x0000, 0x0000, 0x7000, 0x4000, 0x7000, 0x4000, 0x7000, // e
    0x0000, 0x0000, 0x7000, 0x4000, 0x7000, 0x4000, 0x4000, // f
    0x7800, 0x8000, 0x8000, 0x8000, 0x9800, 0x8800, 0x7000, // g
    0x8800, 0x8800, 0x8800, 0xFFFF, 0x8800, 0x8800, 0x8800, // h
    0x7000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x7000, // i
    0x7000, 0x1000, 0x1000, 0x1000, 0x1000, 0x9000, 0x6000, // j
    0x8800, 0x9000, 0xA000, 0xC000, 0xA000, 0x9000, 0x8800, // k
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0xFFFF, // l
    0x8800, 0xD800, 0xA800, 0x8800, 0x8800, 0x8800, 0x8800, // m
    0x8800, 0xC800, 0xC800, 0xA800, 0x9800, 0x9800, 0x8800, // n
    0x7000, 0x8800, 0x8800, 0x8800, 0x8800, 0x8800, 0x7000, // o
    0xF000, 0x8800, 0x8800, 0xF000, 0x8000, 0x8000, 0x8000, // p
    0x7000, 0x8800, 0x8800, 0x8800, 0x8800, 0x7000, 0x1800, // q
    0x0000, 0x0000, 0x7000, 0x4000, 0x4000, 0x4000, 0x4000, // r
    0x0000, 0x0000, 0x7000, 0x4000, 0x7000, 0x1000, 0x7000, // s
    0xFFFF, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, // t
    0x0000, 0x0000, 0x5000, 0x5000, 0x5000, 0x5000, 0x7000, // u
    0x8800, 0x8800, 0x8800, 0x5000, 0x5000, 0x5000, 0x2000, // v
    0x8800, 0x8800, 0x8800, 0x8800, 0xA800, 0xA800, 0x5000, // w
    0x8800, 0x8800, 0x5000, 0x2000, 0x5000, 0x8800, 0x8800, // x
    0x8800, 0x8800, 0x5000, 0x2000, 0x2000, 0x2000, 0x2000, // y
    0xFFFF, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000, 0xFFFF, // z
    0x1800, 0x1000, 0x1000, 0x1000, 0x2000, 0x2000, 0x1000, // {
    0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, // |
    0x3000, 0x1000, 0x1000, 0x1000, 0x0800, 0x0800, 0x1000, // }
    0x0000, 0x0000, 0x0000, 0x7400, 0x4C00, 0x0000, 0x0000  // ~
};
// clang-format on

} // namespace ssd1306
