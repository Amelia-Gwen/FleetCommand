#pragma once

#include "View.h"

namespace fleet {

	constexpr float game_button_panel_width = screen_width_float;
	constexpr float game_button_width = game_button_panel_width / 4.F;
	constexpr float game_button_height = 100.F;
	constexpr float game_button_1_x = 0.F;
	constexpr float game_button_2_x = game_button_width;
	constexpr float game_button_3_x = game_button_2_x + game_button_width;
	constexpr float game_button_4_x = game_button_3_x + game_button_width;
	constexpr float game_button_y = screen_height_float - game_button_height;
	constexpr float game_button_text_y_offset = 20.F;
	constexpr float game_button_text_y = game_button_y + game_button_text_y_offset;

}