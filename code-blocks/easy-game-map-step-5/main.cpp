#include <iostream>
#include "../../include/easy-game-map-calc.hpp"

int main() {
    std::cout << "Hello world!" << std::endl;
    egm::Vec2D<int64_t> point(3,3);

    std::cout << "for square" << std::endl;
    std::vector<egm::ChunkId> list_chunks = egm::get_list_square_area_chunks(point, 500, 64);
    for(size_t i = 0; i < list_chunks.size(); ++i) {
        std::cout << list_chunks[i].x << " " << list_chunks[i].y << std::endl;
    }

    std::cout << "for circle" << std::endl;
    std::vector<egm::ChunkId> list_chunks2 = egm::get_list_circle_area_chunks(point, 250, 64);
    for(size_t i = 0; i < list_chunks2.size(); ++i) {
        std::cout << list_chunks2[i].x << " " << list_chunks2[i].y << std::endl;
    }
    return 0;
}
