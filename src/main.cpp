#include "Game.h"
#include <enet/enet.h>

int main() {
    enet_packet_destroy(NULL);
    Game game(1280, 800, 60);
    game.run();
    return 0;
}