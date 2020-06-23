#ifndef EASY_GAME_MAP_COMMON_HPP_INCLUDED
#define EASY_GAME_MAP_COMMON_HPP_INCLUDED

namespace egm {

    /** \brief Класс для хранения ID чанка
     */
    class ChunkId {
    public:
        int64_t x;  /**< ID чанка по оси X */
        int64_t y;  /**< ID чанка по оси Y */
        ChunkId() {};
    };

};

#endif // EASY_GAME_MAP_COMMON_HPP_INCLUDED
