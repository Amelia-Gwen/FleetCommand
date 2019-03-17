#pragma once

namespace fleet {

	constexpr float drop_button_width = 200.F;
	constexpr float drop_button_height = 80.F;
	constexpr float drop_menu_text_y_offset = 10.F;
	constexpr float drop_menu_x = 0.F;
	constexpr float drop_menu_y = 0.F;
	constexpr float save_y = drop_menu_y + drop_button_height;
	constexpr float exit_y = save_y + drop_button_height;
	constexpr float drop_menu_text_x = drop_menu_x + 50.F;
	constexpr float menu_text_y = drop_menu_y + drop_menu_text_y_offset;
	constexpr float save_text_y = save_y + drop_menu_text_y_offset;
	constexpr float exit_text_y = exit_y + drop_menu_text_y_offset;

	class DropDownMenu {

	};
}