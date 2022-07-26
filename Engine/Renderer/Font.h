#pragma once
#include <string>
#include <SDL_TTF.h>

struct _TTF_FONT
{
	std::string font;
	int fontsize;
};

namespace Engine
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontsize);

		// friend class Text;

	private:

		_TTF_Font* ttfFont_ = nullptr;
		
	};
}