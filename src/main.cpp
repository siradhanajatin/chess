#include <iostream>
#include "raylib.h"

int main() {
    InitWindow(800, 800, "Chess - Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Chess board coming soon...", 220, 380, 20, BLACK);
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}