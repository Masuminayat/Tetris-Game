#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    
    InitWindow(500, 620, "raylib Tetris");
    SetTargetFPS(60);

  
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Texture2D background = LoadTexture("background.png"); 

    
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        
        BeginDrawing();

        
        DrawTexture(background, 0, 0, WHITE); 

        
        DrawTextEx(font, "Score", {16, 25}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {16, 160}, 38, 2, WHITE);
        DrawTextEx(font, "Created By MasumAbbas", {13, 575}, 15, 1, WHITE);

        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {13, 540}, 38, 2, darkBlue);
        }

        DrawRectangleRounded({10, 70, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {10 + (170 - textSize.x) / 2, 80}, 38, 2, WHITE);

        DrawRectangleRounded({10, 210, 170, 180}, 0.3, 6, lightBlue);

        
        game.Draw();

        EndDrawing();
    }

    
    UnloadTexture(background);
    UnloadFont(font);

    CloseWindow();

    return 0;
}
