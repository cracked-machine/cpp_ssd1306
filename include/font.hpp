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

#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <cstdint>
#include <array>
#include <cstddef>

namespace ssd1306
{

const std::size_t char_map_size {95};

template<std::size_t FONT_SIZE>
class Font
{

public:

	// @brief Construct a new Font object
	Font() = default;

	// @brief function to get a font pixel (16bit half-word).
	// @param idx The position in the font data array to retrieve data
	// @return uint16_t The halfword of data we retrieve
	bool get_pixel(std::size_t idx, uint32_t &bit_line)
	{ 
		if (idx > data.size())
		{
			return false;
		}
		else
		{
			// don't use std::array.at(), this will force exception handling to bloat the linked .elf
			bit_line = static_cast<uint32_t>(data[idx]); 

			return true;
		}
		return true;
	}

	// @brief get the width member variable 
	// @return uint8_t the width value
	uint8_t width() { return m_width; }

	// @brief get tte height member variable 
	// @return uint8_t the height value
	uint8_t height() { return m_height; }

	// @brief helper function to get the size of the private font data array.
	// @return size_t the array size
	std::size_t size() { return data.size(); }

	std::array<char, char_map_size> character_map {
		' ', '!', '"', '#', '$', '%', '&', '\'','(', ')',
		'*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9', ':', ';', '<', '=',
		'>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
		'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[',
		'\\',']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
		'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
		'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		'z', '{', '|', '}', '~'
	};

private:

	// @brief The width of the font in pixels
	static const uint8_t m_width; 

	// @brief The height of the font in pixels
	static const uint8_t m_height;

	// @brief the font data
	static std::array<uint16_t, FONT_SIZE> data;

};

constexpr uint8_t font5x5_height {5};
constexpr uint8_t font5x7_height {7};
constexpr uint8_t font7x10_height {10};
constexpr uint8_t font11x18_height {18};
constexpr uint8_t font16x26_height {26};

// the template class object sizes only contribute to your program size if they are used; otherwise they are not linked
using Font5x5 	= 	Font<font5x5_height * char_map_size>;		// 15408 bytes
using Font5x7 	= 	Font<font5x7_height * char_map_size>;		// 15788 bytes
using Font7x10 	= 	Font<font7x10_height * char_map_size>;		// 16364 bytes
using Font11x18 = 	Font<font11x18_height * char_map_size>;		// 17936 bytes
using Font16x26 = 	Font<font16x26_height * char_map_size>;		// 19456 bytes

} // namespace ssd1306

#endif // __FONT_HPP__
