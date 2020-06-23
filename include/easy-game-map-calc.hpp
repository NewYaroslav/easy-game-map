#ifndef EASY_GAME_MAP_CALC_HPP_INCLUDED
#define EASY_GAME_MAP_CALC_HPP_INCLUDED

#include "easy-game-map-common.hpp"
#include <cmath>

namespace egm {
    /** \brief Получить ID чанка
     * \param chunk_id Уникальный номер чанка
     * \param x координата по оси X
     * \param y координата по оси Y
     * \param chunk_size размер чанка
     */
    template <typename T>
    inline void get_chunk_id(ChunkId &chunk_id, const T x, const T y, const int64_t chunk_size) {
        chunk_id.x = x >= 0 ? (int64_t)x/chunk_size : ((fmod(x, (T)chunk_size) == 0 ? (int64_t)x/chunk_size : (int64_t)(x - (T)chunk_size)/chunk_size));
        chunk_id.y = y >= 0 ? (int64_t)y/chunk_size : ((fmod(y, (T)chunk_size) == 0 ? (int64_t)y/chunk_size : (int64_t)(y - (T)chunk_size)/chunk_size));
    }
};

#endif // EASY_GAME_MAP_CALC_HPP_INCLUDED
