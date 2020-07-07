#ifndef EASY_GAME_MAP_GENERAL_HPP_INCLUDED
#define EASY_GAME_MAP_GENERAL_HPP_INCLUDED

#include "easy-game-map-common.hpp"
#include "easy-game-map-chunk.hpp"

namespace egm {

    template<class T>
    class Map2D {
    private:
        std::map<chunk_id_int_t, std::map<chunk_id_int_t, Chunk<T>>> grid;
    public:

        /** \brief Конструктор класса карты 2D
         * \param chunk_size Размер чанка
         */
        Map2D(const size_t chunk_size) {

        };

        T get(const int64_t x, const int64_t y,  const int64_t z) {

        }

        void set(T &item, const int64_t x, const int64_t y,  const int64_t z) {

        }
    };
};

#endif // EASY_GAME_MAP_GENERAL_HPP_INCLUDED
