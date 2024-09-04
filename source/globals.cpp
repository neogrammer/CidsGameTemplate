#include <globals.h>

Accessor gAcc = {};
sf::RenderWindow gWnd = sf::RenderWindow{ sf::VideoMode{1600U,900U,32U}, "Cid's Game Template" };
sf::View gView = sf::View{ ::gWnd.getDefaultView() };
float gTime = 0.f;
