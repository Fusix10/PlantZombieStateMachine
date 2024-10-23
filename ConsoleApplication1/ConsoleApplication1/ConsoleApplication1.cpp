// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Garden.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Plant.hpp"
int main()
{

    sf::RenderWindow window(sf::VideoMode(650, 400), "Pvz");
   Garden* garden = Garden::Instantiate();
   garden->Init();
   Plant* plant1 = garden->CreatePlant(sf::Vector2f(10.f, 25.f), garden->GetPlantBehaviour(), 5, 0);
   Plant* plant2 = garden->CreatePlant(sf::Vector2f(10.f, 125.f), garden->GetPlantBehaviour(), 5, 0);
   Plant* plant3 = garden->CreatePlant(sf::Vector2f(10.f, 225.f), garden->GetPlantBehaviour(), 5, 0);
   Plant* plant4 = garden->CreatePlant(sf::Vector2f(10.f, 325.f), garden->GetPlantBehaviour(), 5, 0);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {
                float x = sf::Mouse::getPosition(window).x;
                float y = sf::Mouse::getPosition(window).y / 100;
                Zombie* zombie1 = garden->CreateZombie(sf::Vector2f(x, y*100 + 25), garden->GetZombieBehaviour(),sf::Vector2f(0.f,-1.f), y);
            }
        }
        window.clear(sf::Color::Black);
        std::vector<Plant*> plants = garden->GetPlants();
        for(int i = 0;i< plants.size();i++)
        {
            window.draw(*plants[i]->GetSprite());
        }
        std::vector<Zombie*> zombies = garden->GetZombies();
        for (int i = 0; i < zombies.size(); i++)
        {
            window.draw(*zombies[i]->GetSprite());
        }

        window.display();
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
