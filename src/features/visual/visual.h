#pragma once
#include "rendering/renderer.h"

class VisualEnhancement {
private:
    bool playerGlow = true;
    bool lootESP = true;
    float renderDistance = 300.0f;
    
public:
    void Render() {
        if (playerGlow) {
            RenderPlayerGlow();
        }
        
        if (lootESP) {
            RenderLootBoxes();
        }
        
        RenderHealthBars();
        RenderDistance();
    }
    
    void RenderPlayerGlow() {
        for (auto& player : GetPlayers()) {
            if (player.Distance() < renderDistance) {
                DrawGlow(player, GetTeamColor(player));
            }
        }
    }
};