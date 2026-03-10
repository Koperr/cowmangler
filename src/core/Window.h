#include "raylib.h"

struct Window {
    int width;
    int hight;
    const char* title;
    int target_fps;

    Window(int width, int height, const char* title, int target_fps = 144) {
        width = width;
        height = height;
        title = title;
        target_fps = target_fps;

        InitWindow(width, height, title);
        DisableCursor();
        SetTargetFPS(target_fps);
    }

    ~Window() {
        CloseWindow();
    }

    bool ShouldClose() {
        return WindowShouldClose();
    }

    Window(const Window&) = delete;
    Window& operator = (const Window&) = delete;
};