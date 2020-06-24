#include <iostream>
#include "../../include/easy-game-map.hpp"

int main() {
    std::cout << "Hello world!" << std::endl;
    const egm::chunk_id_int_t chunk_size = 3;
    /* проверяем получение центра чанков по их ID
     */
    for(egm::chunk_id_int_t x = -1; x <= 1; ++x)
    for(egm::chunk_id_int_t y = -1; y <= 1; ++y) {
        egm::Vec2D<double> center;
        egm::ChunkId chunk_id(x, y);
        egm::get_chunk_center<double>(center, chunk_id, chunk_size);
        std::cout << "(" << chunk_id.x << ";" << chunk_id.y << ") x: " << center.x << " y: " << center.y << std::endl;
    }
    return 0;
}
