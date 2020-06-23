#include <iostream>
#include "../../include/easy-game-map.hpp"

int main() {
    std::cout << "Hello world!" << std::endl;
    const size_t chunk_size = 3;
    /* проверяем получение ID чанков
     *
     */
    for(int64_t x = 3; x <= 5; ++x)
    for(int64_t y = 3; y <= 5; ++y) {
        egm::ChunkId chunk_id;
        egm::get_chunk_id(chunk_id, x, y, chunk_size);
        if(chunk_id.x != 1 || chunk_id.y != 1) {
            std::cout << "(1;1) error, chunk id x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
            return -1;
        } else {
            std::cout << "(1;1) chunk id ok, x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
        }
    }

    for(int64_t x = 0; x <= 2; ++x)
    for(int64_t y = 0; y <= 2; ++y) {
        egm::ChunkId chunk_id;
        egm::get_chunk_id(chunk_id, x, y, chunk_size);
        if(chunk_id.x != 0 || chunk_id.y != 0) {
            std::cout << "(0;0) error, chunk id x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
            return -1;
        } else {
            std::cout << "(0;0) chunk id ok, x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
        }
    }

    for(int64_t x = 0; x <= 2; ++x)
    for(int64_t y = -1; y >= -3; --y) {
        egm::ChunkId chunk_id;
        egm::get_chunk_id(chunk_id, x, y, chunk_size);
        if(chunk_id.x != 0 || chunk_id.y != -1) {
            std::cout << "(0;-1) error, chunk id x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
            return -1;
        } else {
            std::cout << "(0;-1) chunk id ok, x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
        }
    }

    for(int64_t x = -1; x >= -3; --x)
    for(int64_t y = -1; y >= -3; --y) {
        egm::ChunkId chunk_id;
        egm::get_chunk_id(chunk_id, x, y, chunk_size);
        if(chunk_id.x != -1 || chunk_id.y != -1) {
            std::cout << "(-1;-1) error, chunk id x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
            return -1;
        } else {
            std::cout << "(-1;-1) chunk id ok, x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
        }
    }

    for(int64_t x = -1; x >= -3; --x)
    for(int64_t y = 0; y <= 2; ++y) {
        egm::ChunkId chunk_id;
        egm::get_chunk_id(chunk_id, x, y, chunk_size);
        if(chunk_id.x != -1 || chunk_id.y != 0) {
            std::cout << "(-1;0) error, chunk id x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
            return -1;
        } else {
            std::cout << "(-1;0) chunk id ok, x: " << chunk_id.x << " y: " << chunk_id.y << std::endl;
        }
    }

    std::cout << "check fractional numbers" << std::endl;
    for(double x = -4; x <= 4; x += 0.25) {
        for(double y = -4; y <= 4; y += 0.25) {
            egm::ChunkId chunk_id;
            egm::get_chunk_id(chunk_id, x, y, chunk_size);
            std::cout << "(" << chunk_id.x << ";" << chunk_id.y << ") x: " << x << " y: " << y << std::endl;
        }
        std::system("pause");
    }
    return 0;
}
