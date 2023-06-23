#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <SFML/Graphics.hpp>

// Dimensiones de la ventana y la cuadrícula
const int WIDTH = 800;
const int HEIGHT = 600;
const int CELL_SIZE = 10;
const int GRID_WIDTH = WIDTH / CELL_SIZE;
const int GRID_HEIGHT = HEIGHT / CELL_SIZE;

// Función para contar los vecinos vivos de una celda
int contarVecinosVivos(bool cuadricula[GRID_WIDTH][GRID_HEIGHT], int x, int y)
{
    int vecinosVivos = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int vecinoX = (x + i + GRID_WIDTH) % GRID_WIDTH;
            int vecinoY = (y + j + GRID_HEIGHT) % GRID_HEIGHT;
            if (cuadricula[vecinoX][vecinoY])
            {
                vecinosVivos++;
            }
        }
    }
    return vecinosVivos;
}
// Función para inicializar la cuadrícula aleatoriamente
void inicializarCuadricula(bool cuadricula[GRID_WIDTH][GRID_HEIGHT])
{
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            cuadricula[i][j] = rand() % 2;
        }
    }
}

// Función para dibujar la cuadrícula en la ventana
void dibujarCuadricula(sf::RenderWindow &ventana, bool cuadricula[GRID_WIDTH][GRID_HEIGHT])
{
    ventana.clear();
    sf::RectangleShape celda(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {

            if (cuadricula[i][j])
            {
                celda.setFillColor(sf::Color::White);
            }
            else
            {
                celda.setFillColor(sf::Color::Black);
            }
            celda.setPosition(i * CELL_SIZE, j * CELL_SIZE);
            ventana.draw(celda);
        }
    }

    ventana.display();
}
void dibujarCuadriculaRand(sf::RenderWindow &ventana, bool cuadricula[GRID_WIDTH][GRID_HEIGHT])
{
    ventana.clear();
    // randomize color
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;

    sf::RectangleShape celda(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {

            if (cuadricula[i][j])
            {
                celda.setFillColor(sf::Color(r, g, b));
            }
            else
            {
                celda.setFillColor(sf::Color::Black);
            }
            celda.setPosition(i * CELL_SIZE, j * CELL_SIZE);
            ventana.draw(celda);
        }
    }

    ventana.display();
}
void dibujarCuadriculaParty(sf::RenderWindow &ventana, bool cuadricula[GRID_WIDTH][GRID_HEIGHT])
{
    ventana.clear();

    sf::RectangleShape celda(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {

            if (cuadricula[i][j])
            {
                // randomize color
                int r = rand() % 255;
                int g = rand() % 255;
                int b = rand() % 255;
                celda.setFillColor(sf::Color(r, g, b));
            }
            else
            {
                celda.setFillColor(sf::Color::Black);
            }
            celda.setPosition(i * CELL_SIZE, j * CELL_SIZE);
            ventana.draw(celda);
        }
    }

    ventana.display();
}

// Función para actualizar la cuadrícula según las reglas del juego de la vida
void actualizarCuadricula(bool cuadricula[GRID_WIDTH][GRID_HEIGHT])
{
    bool nuevaCuadricula[GRID_WIDTH][GRID_HEIGHT];

    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            int vecinosVivos = contarVecinosVivos(cuadricula, i, j);
            if (cuadricula[i][j])
            {
                nuevaCuadricula[i][j] = (vecinosVivos == 2 || vecinosVivos == 3);
            }
            else
            {
                nuevaCuadricula[i][j] = (vecinosVivos == 3);
            }
        }
    }

    for (int i = 0; i < GRID_WIDTH; i++)
    {
        for (int j = 0; j < GRID_HEIGHT; j++)
        {
            cuadricula[i][j] = nuevaCuadricula[i][j];
        }
    }
}

int main()
{
    std::cout << "Juego de la vida" << std::endl;
    std::cout << "Elija el modo" << std::endl
              << "[1] Clásico" << std::endl
              << "[2] Color random" << std::endl
              << "[3] Color Party " << std::endl;

    int modo;
    std::cin >> modo;

    bool cuadricula[GRID_WIDTH][GRID_HEIGHT];
    inicializarCuadricula(cuadricula);

    sf::RenderWindow ventana(sf::VideoMode(WIDTH, HEIGHT), "Juego de la Vida");

    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                ventana.close();
            }
        }

        switch (modo)
        {
        case 1:
            dibujarCuadricula(ventana, cuadricula);
            break;
        case 2:
            dibujarCuadriculaRand(ventana, cuadricula);
            break;
        case 3:
            dibujarCuadriculaParty(ventana, cuadricula);
            break;

        default:
            break;
        }
        actualizarCuadricula(cuadricula);

        usleep(100000); // Pausa de 100 milisegundos
    }

    return 0;
}
