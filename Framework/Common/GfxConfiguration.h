//.h implies that this file is a C-style header
// if cpp-header, i would specify it as .hpp

#pragma once

#include <cstdint>
#include <ostream>
namespace My {
struct GfxConfiguration { // Gfx stands for Graphics
  GfxConfiguration(uint32_t r = 8, uint32_t g = 8, uint32_t b = 8,
                   uint32_t a = 8, uint32_t depth = 24, uint32_t stencil = 0,
                   uint32_t msaa = 0, uint32_t width = 1920,
                   uint32_t height = 1080,
                   const char *name = "Aganes Wickfield")
      : redBits(r), greenBits(g), blueBits(b), alphaBits(a), depthBits(depth),
        stencilBits(stencil), msaaSamples(msaa), screenWidth(width),
        screenHeight(height), appName(name) {}

  uint32_t redBits;
  uint32_t greenBits;
  uint32_t blueBits;
  uint32_t alphaBits;
  uint32_t depthBits;
  uint32_t stencilBits;
  uint32_t msaaSamples;
  uint32_t screenWidth;
  uint32_t screenHeight;
  const char *appName;

  friend std::ostream &operator<<(std::ostream &out,
                                  const GfxConfiguration &config) {
    out << "GfxConfiguration: { " << std::endl
        << "R:" << config.redBits << std::endl
        << " G:" << config.greenBits << std::endl
        << " B:" << config.blueBits << std::endl
        << " A:" << config.alphaBits << std::endl
        << " Depth:" << config.depthBits << std::endl
        << " Stencil:" << config.stencilBits << std::endl
        << " MSAA:" << config.msaaSamples << std::endl
        << " Width:" << config.screenWidth << std::endl
        << " Height:" << config.screenHeight << std::endl
        << " }";
    return out;
  }
};

} // namespace My
