#pragma once
#include <string>
#include "Gng2D/types/font.hpp"
#include "Gng2D/gui/element.hpp"

namespace Gng2D::gui
{
struct Text : Element
{
    Text(const std::string& font, const std::string& str);

    void    render(SDL_Renderer*)   const override;
    int     width()                 const override;
    int     height()                const override;

    void    changeFont(const std::string& font);

private:
    Font            font;
    std::string     str;
};
}
