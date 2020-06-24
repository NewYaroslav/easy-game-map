#ifndef EASY_GAME_MAP_COMMON_HPP_INCLUDED
#define EASY_GAME_MAP_COMMON_HPP_INCLUDED

namespace egm {

    /** \brief Класс вектора с двумя компонентами
     */
    template <class T>
    class Vec2D {
    public:
        typedef T value_type;
        T x;
        T y;
        Vec2D() {};
        Vec2D(const T _x, const T _y) : x(_x), y(_y) {};
    };

    typedef Vec2D<int64_t> ChunkId; /**< Класс для хранения ID чанка */
    typedef int64_t chunk_id_int_t; /**< Тип переменной для ID чанка */
    typedef int64_t chunk_int_t;    /**< Тип переменной для координат */
};

#endif // EASY_GAME_MAP_COMMON_HPP_INCLUDED
