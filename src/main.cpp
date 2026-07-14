#include <iostream>
#include "raylib.h"

int main() {
    InitWindow(640, 640, "Chess - Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (i%2==0) {
                    DrawRectangle( 0+(160*j), 0+(80*i), 80, 80, BLACK);
                } else {
                    DrawRectangle( 80+(160*j), 0+(80*i), 80, 80, BLACK);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}