#include <iostream>
#include <string>
#include <unordered_map>
#include "raylib.h"

int main() {

    const int windowSize = 640;
    const int cellSize = windowSize / 8;

    InitWindow(windowSize, windowSize, "Chess - Raylib");
    SetTargetFPS(60);

    const char *board[8] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    std::unordered_map<char, std::string> piecePaths = {
        {'r', "chess-pieces/br.png"},
        {'n', "chess-pieces/bn.png"},
        {'b', "chess-pieces/bb.png"},
        {'q', "chess-pieces/bq.png"},
        {'k', "chess-pieces/bk.png"},
        {'p', "chess-pieces/bp.png"},
        {'R', "chess-pieces/wr.png"},
        {'N', "chess-pieces/wn.png"},
        {'B', "chess-pieces/wb.png"},
        {'Q', "chess-pieces/wq.png"},
        {'K', "chess-pieces/wk.png"},
        {'P', "chess-pieces/wp.png"}
    };

    std::unordered_map<char, Texture2D> textures;
    const std::string assetPath = ASSETS_PATH;

    for (auto &entry : piecePaths) {
        const std::string fullPath = assetPath + entry.second;
        textures[entry.first] = LoadTexture(fullPath.c_str());
        if (textures[entry.first].id == 0) {
            std::cerr << "Failed to load texture: " << fullPath << std::endl;
            return 1;
        }
    }

    const Color lightSquare = {240, 217, 181, 255};
    const Color darkSquare = {181, 136,  99, 255};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                bool isDark = ((7 - row + col) % 2 == 0);
                DrawRectangle(col * cellSize, row * cellSize, cellSize, cellSize, isDark ? darkSquare : lightSquare);
                char piece = board[row][col];
                if (piece != '.') {
                    Texture2D texture = textures[piece];
                    DrawTexturePro(texture, Rectangle{0.0f, 0.0f, (float)texture.width, (float)texture.height}, Rectangle{(float)(col * cellSize), (float)(row * cellSize), (float)cellSize, (float)cellSize}, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
                }
            }
        }

        EndDrawing();
    }

    for (auto &entry : textures) {
        UnloadTexture(entry.second);
    }

    CloseWindow();
    return 0;
}