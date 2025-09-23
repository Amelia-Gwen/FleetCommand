#pragma once

namespace fleet {
	// View
	constexpr unsigned view_width = 1200U;
	constexpr unsigned view_height = 800U;
	constexpr float view_width_float = static_cast<float>(view_width);
	constexpr float view_height_float = static_cast<float>(view_height);

	// Drop Box
	constexpr float dropbox_default_x_offset = 130.F;
	constexpr float box_text_offset = 2.F;
	constexpr float box_default_width = 100.F;
	constexpr float box_default_height = 34.F;
	constexpr float box_default_thickness = 1.F;

	// Drop Down Menu
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

	// Display Panel
	constexpr float panel_x_offset = drop_button_width;
	constexpr float panel_width = view_width_float - panel_x_offset;
	constexpr float panel_box_width = panel_width / 4.F;
	constexpr float panel_box_height = drop_button_height;
	constexpr float panel_1_x = panel_x_offset;
	constexpr float panel_2_x = panel_1_x + panel_box_width;
	constexpr float panel_3_x = panel_2_x + panel_box_width;
	constexpr float panel_4_x = panel_3_x + panel_box_width;
	constexpr float panel_y = 0.F;
	constexpr float name_x_offset = 15.F;
	constexpr float panel_text_x_offset = 80.F;
	constexpr float panel_text_y_offset = 15.F;
	constexpr float name_x = panel_1_x + name_x_offset;
	constexpr float oil_x = panel_2_x + panel_text_x_offset;
	constexpr float cash_x = panel_3_x + panel_text_x_offset;
	constexpr float research_x = panel_4_x + panel_text_x_offset;
	constexpr float panel_text_y = panel_y + panel_text_y_offset;

	// IScreen
	constexpr unsigned text_character_size = 45U;
	constexpr float menu_back_button_width = 100.F;
	constexpr float menu_back_button_height = 50.F;
	constexpr float menu_back_x = 0.F;
	constexpr float menu_back_y = 0.F;

	// Main Menu Screen
	constexpr int logo_width = 500;
	constexpr int logo_height = 300;
	constexpr float logo_x = 350.F;
	constexpr float logo_y = 100.F;
	constexpr float logo_text_x = logo_x + 90.F;
	constexpr float logo_text_y = logo_y + 80.F;
	constexpr float main_menu_button_width = 300.F;
	constexpr float main_menu_button_height = 75.F;
	constexpr float main_menu_button_x = 450.F;
	constexpr float play_button_y = 600.F;
	constexpr float new_game_button_y = 500.F;
	constexpr float load_button_y = 650.F;
	constexpr unsigned logo_text_character_size = 60;

	// New Game Screen
	constexpr float new_button_width = 400.F;
	constexpr float new_button_height = 400.F;
	constexpr float campaign_button_x = 150.F;
	constexpr float custom_button_x = 650.F;
	constexpr float new_button_y = 200.F;
	constexpr float new_game_text_y = new_button_y + 100.F;
	constexpr unsigned new_text_size = 60U;

	// Load Game Screen
	constexpr float slot_width = 300.F;
	constexpr float slot_height = 300.F;
	constexpr float slot1_x = 50.F;
	constexpr float slot2_x = 450.F;
	constexpr float slot3_x = 850.F;
	constexpr float slot_y = 300.F;

	// Custom Menu Screen
	constexpr float column_one_x = 300.F;
	constexpr float column_two_x = 700.F;
	constexpr float row_one_y = 100.F;
	constexpr float row_two_y = 300.F;
	constexpr float row_three_y = 500.F;
	constexpr float start_button_width = 300.F;
	constexpr float start_button_height = 75.F;
	constexpr float start_button_x = 400.F;
	constexpr float start_button_y = 700.F;
	constexpr float start_x_offset =  40.F;
	constexpr unsigned max_players = 4U;

	// Game Screens
	constexpr float game_button_panel_width = view_width_float;
	constexpr float game_button_width = game_button_panel_width / 4.F;
	constexpr float game_button_height = 100.F;
	constexpr float game_button_1_x = 0.F;
	constexpr float game_button_2_x = game_button_width;
	constexpr float game_button_3_x = game_button_2_x + game_button_width;
	constexpr float game_button_4_x = game_button_3_x + game_button_width;
	constexpr float game_button_y = view_height_float - game_button_height;

	// IMap
	constexpr float map_width = view_width_float;
	constexpr float map_height = view_height_float - (drop_button_height + game_button_height);
	constexpr float map_button_side = 30.F;
	constexpr float map_button_y = 650.F;
	constexpr float zoom_in_x = 60.F;
	constexpr float zoom_out_x = 120.F;
	constexpr unsigned minimum_scale = 1;
	constexpr unsigned maximum_scale = 10;
	constexpr float city_position_multiplier_x = 5.F;
	constexpr float city_position_multiplier_y = 5.F;
	constexpr unsigned city_name_text_size = 10U;
	constexpr float city_text_offset_x = -15.F;
	constexpr float city_text_offset_y = 12.F;

	// World Map
	constexpr float world_x_offset = 60.F;
	constexpr float world_map_city_width = 10.F;
	constexpr float world_map_city_height = 10.F;

	// City Map
	constexpr float tile_outline = 5.f;
	constexpr float tile_height = (map_height / 20.f) - (tile_outline * 2.f);

	// Button Offsets
	constexpr float back_x_offset = 20.F;
	constexpr float load_x_offset = 50.F;
	constexpr float play_button_x_offset = 100.F;
	constexpr float new_or_load_x_offset = 40.F;
	constexpr float new_text_x_offset = 80.F;
	constexpr float dashboard_x_offset = 60.F;
	constexpr float research_x_offset = 60.F;
	constexpr float fleet_x_offset = 100.F;
	constexpr float endturn_x_offset = 60.F;
	constexpr float citymap_x_offset = 60.F;
	constexpr float cityname_x_offset = 50.F;
	constexpr float cityupgrade_x_offset = 20.F;
	constexpr float worldmap_x_offset = 50.F;
	constexpr float unit_x_offset = 100.F;
	constexpr float game_text_y_offset = 20.F;
	constexpr float menu_text_y_offset = 10.F;

	// UpgradeButtons
	constexpr float default_upgrade_width = 80.F;
	constexpr float default_upgrade_height = 120.F;
	constexpr float default_indicator_height = 20.F;
	constexpr float upgrade_label_y_offset = 10.F;
	constexpr float upgrade_button_outline = 2.F;
	constexpr float text_box_outline = 2.F;
	constexpr float description_text_offset = 5.F;
	constexpr unsigned description_character_size = 15U;
	constexpr unsigned max_label_length = 30U;

	// UnitButtons
	constexpr float default_unit_button_width = 100.F;
	constexpr float default_unit_button_height = 140.F;
	constexpr float default_cost_y_offset = 120.F;
	constexpr float unit_column_one_x = 100.F;
	constexpr float unit_column_two_x = 310.F;
	constexpr float unit_column_three_x = 525.F;
	constexpr float unit_column_four_x = 730.F;
	constexpr float unit_row_one_y = 120.F;
	constexpr float unit_row_two_y = 300.F;
	constexpr float unit_row_three_y = 480.F;
	constexpr float unit_text_box_x = 930.F;
	constexpr float unit_text_box_y = 120.F;
	constexpr float unit_text_box_width = 250.F;
	constexpr float unit_text_box_height = 520.F;

	// Research Screen Upgrade Buttons
	constexpr float research_column_one_x = 100.F;
	constexpr float research_column_two_x = 310.F;
	constexpr float research_column_three_x = 525.F;
	constexpr float research_column_four_x = 730.F;
	constexpr float research_row_one_y = 120.F;
	constexpr float research_row_two_y = 300.F;
	constexpr float research_row_three_y = 480.F;
	constexpr float research_text_box_x = 930.F;
	constexpr float research_text_box_y = 120.F;
	constexpr float research_text_box_width = 250.F;
	constexpr float research_text_box_height = 520.F;

	// City Upgrade Screen Upgrade Buttons
	constexpr float city_upgrade_column_one_x = 100.F;
	constexpr float city_upgrade_column_two_x = 340.F;
	constexpr float city_upgrade_column_three_x = 580.F;
	constexpr float city_upgrade_row_one_y = 200.F;
	constexpr float city_upgrade_row_two_y = 450.F;
	constexpr float city_upgrade_text_box_x = 850.F;
	constexpr float city_upgrade_text_box_y = 200.F;
	constexpr float city_upgrade_text_box_width = 300.F;
	constexpr float city_upgrade_text_box_height = 410.F;
}