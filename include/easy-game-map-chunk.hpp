#ifndef EASY_GAME_MAP_CHUNK_HPP_INCLUDED
#define EASY_GAME_MAP_CHUNK_HPP_INCLUDED

#include "easy-game-map-common.hpp"
#include <vector>
#include <memory>
#include <functional>

namespace egm {

    /** \brief Класс для хранения чанка карты
     */
    template <class T>
    class Chunk {
    private:
        Vec2D<int64_t> chunk_bottom_left;
        ChunkId chunk_id;
        chunk_int_t chunk_size;
        chunk_int_t levels;
        chunk_int_t offset_z;
        std::vector<std::shared_ptr<T>> data;
        std::function<void(
            const ChunkId &chunk_id,
            std::vector<std::shared_ptr<T>> &data)> construction_callback;
        std::function<void(
            const ChunkId &chunk_id,
            std::vector<std::shared_ptr<T>> &data)> destruction_callback;

        void init() {
            if(chunk_size == 0 || levels == 0) return;
            get_chunk_bottom_left(chunk_bottom_left, chunk_id, chunk_size);
            offset_z = chunk_size * chunk_size;
            const size_t data_size = offset_z * levels;
            data.resize(data_size);
        }

        /** \brief Найти смещение в массиве
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         * \return смещение
         */
        inline size_t calc_offset(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z) {
            return x + y * chunk_size + z * offset_z;
        }

    public:

        Chunk() : chunk_id(0,0), chunk_size(0), levels(0) {};

        Chunk(
                const ChunkId &_chunk_id,
                const size_t _chunk_size,
                const size_t _levels = 1,
                std::function<void(
                    const ChunkId &chunk_id,
                    std::vector<std::shared_ptr<T>> &data)> _construction_callback = nullptr,
                std::function<void(
                    const ChunkId &chunk_id,
                    std::vector<std::shared_ptr<T>> &data)> _destruction_callback = nullptr) :
                chunk_id(_chunk_id), chunk_size(_chunk_size), levels(_levels),
                construction_callback(_construction_callback),
                destruction_callback(_destruction_callback) {
            init();
            if(construction_callback != nullptr) construction_callback(chunk_id, data);
        };

        ~Chunk() {
            if(destruction_callback != nullptr) destruction_callback(chunk_id, data);
        }

        /** \brief Получить ссылку на весь массив данных чанка
         * \return ссылка на весь массив данных чанка
         */
        inline std::vector<std::shared_ptr<T>> &get() {
            return data;
        }

        /** \brief Проверить чанк
         * \return Вернет true, если чан инициализирован
         */
        inline bool check() {
            return (data.size() != 0);
        }

        /** \brief Получить элемент чанка для относительных координат без защиты
         * Данная функция вернет элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         * \return указатель на элемент чанка или nullptr, если элемент нет
         */
        inline std::shared_ptr<T> get_relative_no_protection(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            return data[calc_offset(x, y, z)];
        }

        /** \brief Получить элемент чанка для относительных координат
         * Данная функция вернет элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         * \return указатель на элемент чанка или nullptr, если элемент нет
         */
        inline std::shared_ptr<T> get_relative(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            if(x >= chunk_size || y >= chunk_size || z >= levels || x < 0 || y < 0 || z < 0) return std::shared_ptr<T>(nullptr);
            if(data.size() == 0) return std::shared_ptr<T>(nullptr);
            return data[calc_offset(x, y, z)];
        }

        /** \brief Получить элемент чанка для абсолютных координат без защиты
         * Данная функция вернет элемент чанка, расположенный в абсолютной системе координат
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         * \return указатель на элемент чанка или nullptr, если элемент нет
         */
        inline std::shared_ptr<T> get_absolute_no_protection(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            return data[calc_offset(x - chunk_bottom_left.x, y - chunk_bottom_left.y, z)];
        }

        /** \brief Получить элемент чанка для абсолютных координат
         * Данная функция вернет элемент чанка, расположенный в абсолютной системе координат
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         * \return указатель на элемент чанка или nullptr, если элемент нет
         */
        inline std::shared_ptr<T> get_absolute(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            return get_relative(x - chunk_bottom_left.x, y - chunk_bottom_left.y, z);
        }

        /** \brief Удалить элемент чанка для относительных координат без защиты
         * Данная функция удаляет элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         */
        inline void delete_relative_no_protection(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            const size_t offset = calc_offset(x, y, z);
            if(data[offset]) data[offset].reset();
        }

        /** \brief Удалить элемент чанка для относительных координат
         * Данная функция удаляет элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         */
        inline void delete_relative(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            if(x >= chunk_size || y >= chunk_size || z >= levels || x < 0 || y < 0 || z < 0) return;
            if(data.size() == 0) return;
            const size_t offset = calc_offset(x, y, z);
            if(data[offset]) data[offset].reset();
        }

        /** \brief Удалить элемент чанка для абсолютных координат без защиты
         * Данная функция удаляет элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         */
        inline void delete_absolute_no_protection(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            const size_t offset = calc_offset(x - chunk_bottom_left.x, y - chunk_bottom_left.y, z);
            if(data[offset]) data[offset].reset();
        }

        /** \brief Удалить элемент чанка для абсолютных координат
         * Данная функция удаляет элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         */
        inline void delete_absolute(const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            delete_relative(x - chunk_bottom_left.x, y - chunk_bottom_left.y, z);
        }

        /** \brief Добавить элемент чанка для относительных координат
         * Данная функция добавляет элемент чанка
         * \param item Новый элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         */
        inline bool add_relative(std::shared_ptr<T> &item, const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            if(x >= chunk_size || y >= chunk_size || z >= levels || x < 0 || y < 0 || z < 0) return false;
            if(data.size() == 0) return false;
            data[calc_offset(x, y, z)] = item;
            return true;
        }

        /** \brief Добавить элемент чанка для абсолютных координат
         * Данная функция добавляет элемент чанка
         * \param item Новый элемент чанка
         * \param x координаты элемента чанка
         * \param y координаты элемента чанка
         * \param z координаты элемента чанка
         */
        inline bool add_absolute(std::shared_ptr<T> &item, const chunk_int_t x, const chunk_int_t y, const chunk_int_t z = 0) {
            return add_relative(item, x - chunk_bottom_left.x, y - chunk_bottom_left.y, z);
        }

    };
}

#endif // EASY-GAME-MAP-CHUNK_HPP_INCLUDED
