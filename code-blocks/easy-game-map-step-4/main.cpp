#include <iostream>
#include "../../include/easy-game-map.hpp"

/** \brief Класс для проверки работы чанков
 */
class Test {
public:
    std::string name;   /**< Имя */

    Test() {};
    Test(const std::string &_name) : name(_name) {};
};

int main() {
    std::cout << "Hello world!" << std::endl;

    /* параметры чанка */
    const egm::chunk_id_int_t chunk_size = 3;
    const size_t level = 3;
    egm::ChunkId chunk_id(0,0);

    /* конструктор чанка */
    egm::Chunk<Test> chunk(chunk_id, chunk_size, level,
        [&](const egm::ChunkId &chunk_id, std::vector<std::shared_ptr<Test>> &data) {
            std::cout << "chunk(" << chunk_id.x << ";" << chunk_id.y << ") construction!" << std::endl;
            for(size_t i = 0; i < data.size(); ++i) {
                if(i % 9 == 0) {
                    data[i] =  std::make_shared<Test>("Protectron");
                    std::cout << "add robot Protectron" << std::endl;
                }
            }
        },
        [&](const egm::ChunkId &chunk_id, std::vector<std::shared_ptr<Test>> &data) {
             std::cout << "chunk(" << chunk_id.x << ";" << chunk_id.y << ") destruction!" << std::endl;
             for(size_t i = 0; i < data.size(); ++i) {
                if(data[i]) std::cout << "robot(" << i << "): " << data[i]->name << std::endl;
             }
    });

    if(!chunk.check()) {
        std::cout << "chunk check error!" << std::endl;
        return -1;
    }

    /* создаем объект с именем Robby по координатам 0,0,0 */
    {
        std::shared_ptr<Test> robot = std::make_shared<Test>("Robby");
        chunk.add_relative(robot, 0,0,0);
        std::cout << "add robot1 Robby" << std::endl;
    }

    /* создаем объект с именем R2D2 по координатам 2,2,0 */
    {
        std::shared_ptr<Test> robot2 = std::make_shared<Test>("R2D2");
        chunk.add_absolute(robot2, 2,2,0);
        std::cout << "add robot2 R2D2" << std::endl;
    }

    /* создаем объект с именем MegaBot по координатам 1,1,2 */
    {
        std::shared_ptr<Test> robot3 = std::make_shared<Test>("MegaBot");
        chunk.add_absolute(robot3, 1,1,2);
        std::cout << "add robot3 MegaBot" << std::endl;
    }

    /* проверяем объект по координатам 0,0,0 */
    {
        std::shared_ptr<Test> robot = chunk.get_relative(0,0,0);
        if(robot) {
            std::cout << "robot1: " << robot->name << std::endl;
        } else {
            std::cout << "robot1 is null" << std::endl;
        }
    }

    /* проверяем объект по координатам 0,0,0 */
    {
        std::shared_ptr<Test> robot = chunk.get_absolute(0,0,0);
        if(robot) {
            std::cout << "robot1: " << robot->name << std::endl;
        } else {
            std::cout << "robot1 is null" << std::endl;
        }
    }

    /* удаляем объект по координатам 0,0,0 */
    chunk.delete_absolute(0,0,0);
    std::cout << "delete robot1" << std::endl;

    /* проверяем объект по координатам 0,0,0 */
    {
        std::shared_ptr<Test> robot = chunk.get_absolute(0,0,0);
        if(robot) {
            std::cout << "robot1: " << robot->name << std::endl;
        } else {
            std::cout << "robot1 is null" << std::endl;
        }
    }

    /* проверяем объект по координатам 2,2,0 */
    {
        std::shared_ptr<Test> robot = chunk.get_absolute(2,2,0);
        if(robot) {
            std::cout << "robot2: " << robot->name << std::endl;
        } else {
            std::cout << "robot2 is null" << std::endl;
        }
    }

    /* проверяем объект по координатам 1,1,2 */
    {
        std::shared_ptr<Test> robot = chunk.get_absolute(1,1,2);
        if(robot) {
            std::cout << "robot3: " << robot->name << std::endl;
        } else {
            std::cout << "robot3 is null" << std::endl;
        }
    }


    return 0;
}
