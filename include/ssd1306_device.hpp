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

// @note See datasheet
// https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf

#ifndef __SSD1306_DEVICE_HPP__
#define __SSD1306_DEVICE_HPP__

#include <ssd1306_common.hpp>

// disable dynamic allocation/copying
#include <restricted_base.hpp>

namespace ssd1306
{

// @brief contains pointer to SPI peripheral and associated GPIO ports/pins (as defined in CMSIS)
template <typename DEVICE_ISR_ENUM>
class DriverSerialInterface
{
public:
  // @brief Construct a new ssd1306::DriverSerialInterface object
  // @param display_spi   The SPI peripheral e.g. SPI1
  // @param dc_port       The data/command port e.g. GPIOA
  // @param dc_pin        The data/command pin e.g. LL_GPIO_PIN_0
  // @param reset_port    The reset port e.g. GPIOA
  // @param reset_pin     The reset pin e.g. LL_GPIO_PIN_3
  DriverSerialInterface(SPI_TypeDef *display_spi,
                        std::pair<GPIO_TypeDef *, uint16_t> dc_gpio,
                        std::pair<GPIO_TypeDef *, uint16_t> reset_gpio,
                        DEVICE_ISR_ENUM dma_isr_type)
      : m_display_spi(*display_spi),
        m_dc_port(*dc_gpio.first),
        m_dc_pin(dc_gpio.second),
        m_reset_port(*reset_gpio.first),
        m_reset_pin(reset_gpio.second),
        m_dma_isr_type(dma_isr_type)
  {
  }
  SPI_TypeDef &get_spi_handle() { return m_display_spi; }
  GPIO_TypeDef &get_dc_port() { return m_dc_port; }
  uint16_t get_dc_pin() { return m_dc_pin; }
  GPIO_TypeDef &get_reset_port() { return m_reset_port; }
  uint16_t get_reset_pin() { return m_reset_pin; }
  DEVICE_ISR_ENUM get_dma_isr_type() { return m_dma_isr_type; }

private:
  // @brief The SPI peripheral
  SPI_TypeDef &m_display_spi;
  // @brief The data/command GPIO port object
  GPIO_TypeDef &m_dc_port;
  // @brief The data/command GPIO pin
  uint16_t m_dc_pin;
  // @brief The reset GPIO port object
  GPIO_TypeDef &m_reset_port;
  // @brief The reset GPIO pin
  uint16_t m_reset_pin;

  DEVICE_ISR_ENUM m_dma_isr_type;
};

} // namespace ssd1306

#endif // __SSD1306_DEVICE_HPP__