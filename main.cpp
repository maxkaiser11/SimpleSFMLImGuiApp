#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window Title");
    ImGui::SFML::Init(window);

    bool circleExists = true;
    float circleRadius = 200.0f;
    int circleSegments = 100;
    float circleRotation = 90.f;
    float x = 400;
    float y = 400;
    float circleColor[3] = { (float)204 / 255, (float)77 / 255, (float)5 / 255 };
    sf::CircleShape shape(circleRadius, circleSegments);
    shape.setFillColor(sf::Color(
        (int)(circleColor[0] * 255),
        (int)(circleColor[1] * 255),
        (int)(circleColor[2] * 255)
    )); // Color circle
    shape.setRotation(circleRotation);
    shape.setOrigin(circleRadius, circleRadius);
    shape.setPosition(x, y); // Center circle
 

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Edit Shape");
        ImGui::Text("Edit Shape Properties");
        ImGui::Checkbox("Circle", &circleExists);
        ImGui::SliderFloat("Radius", &circleRadius, 100.f, 300.f);
        ImGui::SliderInt("Segments", &circleSegments, 3, 150);
        ImGui::SliderFloat("Rotation", &circleRotation, 0.f, 360.f);
        ImGui::SliderFloat("Move in X", &x, 0.f, 800.f);
        ImGui::SliderFloat("Move in Y", &y, 0.f, 800.f);
        ImGui::ColorEdit3("Color Circle", circleColor);
        ImGui::End();

        shape.setRadius(circleRadius);
        shape.setOrigin(circleRadius, circleRadius);
        shape.setPointCount(circleSegments);
        shape.setRotation(circleRotation);
        shape.setFillColor(sf::Color(
            (int)(circleColor[0] * 255),
            (int)(circleColor[1] * 255),
            (int)(circleColor[2] * 255)
        ));
        shape.setPosition(x, y);

        window.clear(sf::Color(18, 33, 43)); // Color background
        if (circleExists)
            window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }


    ImGui::SFML::Shutdown();
    return 0;
}