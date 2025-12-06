void gui_button(int x, int y, int w, int h, const char* text, uint32_t color) {
    gui_draw_rect(x, y, w, h, color);
    gui_draw_text(x + 20, y + 12, text, 0xFFFFFF);
}
