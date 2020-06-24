#include <iostream>
#include "../../include/easy-game-map.hpp"

int main() {
    std::cout << "Hello world!" << std::endl;
    const egm::chunk_id_int_t chunk_size = 3;
    /* проверяем получение координат углов чанков по их ID
     */
    std::cout << "top left" << std::endl;
    for(egm::chunk_id_int_t x = -1; x <= 1; ++x)
    for(egm::chunk_id_int_t y = -1; y <= 1; ++y) {
        egm::Vec2D<double> top_left;
        egm::ChunkId chunk_id(x,y);
        egm::get_chunk_top_left(top_left, chunk_id, chunk_size);
        std::cout << "(" << chunk_id.x << ";" << chunk_id.y << ") x: " << top_left.x << " y: " << top_left.y << std::endl;
    }
    std::cout << "bottom left" << std::endl;
    for(egm::chunk_id_int_t x = -1; x <= 1; ++x)
    for(egm::chunk_id_int_t y = -1; y <= 1; ++y) {
        egm::Vec2D<double> bottom_left;
        egm::ChunkId chunk_id(x,y);
        egm::get_chunk_bottom_left(bottom_left, chunk_id, chunk_size);
        std::cout << "(" << chunk_id.x << ";" << chunk_id.y << ") x: " << bottom_left.x << " y: " << bottom_left.y << std::endl;
    }
    return 0;
}
