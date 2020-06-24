#ifndef EASY_GAME_MAP_CALC_HPP_INCLUDED
#define EASY_GAME_MAP_CALC_HPP_INCLUDED

#include "easy-game-map-common.hpp"
#include <cmath>

namespace egm {
    /** \brief Получить ID чанка
     * Данная функция находит ID чанка по указанным координатам
     * \param chunk_id Уникальный номер чанка
     * \param x координата по оси X
     * \param y координата по оси Y
     * \param chunk_size размер чанка
     */
    template <class T>
    inline void get_chunk_id(ChunkId &chunk_id, const T x, const T y, const chunk_id_int_t chunk_size) {
        chunk_id.x = x >= 0 ? (chunk_id_int_t)x/chunk_size : ((fmod(x, (T)chunk_size) == 0 ? (chunk_id_int_t)x/chunk_size : (chunk_id_int_t)(x - (T)chunk_size)/chunk_size));
        chunk_id.y = y >= 0 ? (chunk_id_int_t)y/chunk_size : ((fmod(y, (T)chunk_size) == 0 ? (chunk_id_int_t)y/chunk_size : (chunk_id_int_t)(y - (T)chunk_size)/chunk_size));
    }

    /** \brief Получить центр чанка
     * \param chunk_id Уникальный номер чанка
     * \param center Координаты центра чанка
     * \param chunk_size размер чанка
     */
    template <class T1, class T2, class T3>
    inline void get_chunk_center(T2 &center, const T3 &chunk_id, const chunk_id_int_t chunk_size) {
        const T1 chunk_size_div2 = (T1)chunk_size / 2;
        center.x = chunk_id.x * chunk_size + chunk_size_div2;
        center.y = chunk_id.y * chunk_size + chunk_size_div2;
    }

    /** \brief Получить левый верхний угол чанка
     * \param chunk_id Уникальный номер чанка
     * \param top_left Координаты левого верхнего угла чанка
     * \param chunk_size размер чанка
     */
    template <class T1, class T2>
    inline void get_chunk_top_left(T1 &top_left, const T2 &chunk_id, const chunk_id_int_t chunk_size) {
        top_left.x = chunk_id.x * chunk_size;
        top_left.y = chunk_id.y * chunk_size + chunk_size;
    }

    /** \brief Получить левый нижний угол чанка
     * \param chunk_id Уникальный номер чанка
     * \param top_left Координаты левого верхнего угла чанка
     * \param chunk_size размер чанка
     */
    template <class T1, class T2>
    inline void get_chunk_bottom_left(T1 &bottom_left, const T2 &chunk_id, const chunk_id_int_t chunk_size) {
        bottom_left.x = chunk_id.x * chunk_size;
        bottom_left.y = chunk_id.y * chunk_size;
    }
};

#endif // EASY_GAME_MAP_CALC_HPP_INCLUDED
